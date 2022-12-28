#include <TimerOne.h>
#include "ADC.h"

/* Defines */
/* Puerto serial para la comunicacion con el modulo bluetooth */
#define Bluetooth_Serial      Serial1

/* Puerto serial para depurar */
#define SERIAL_DBG            SerialUSB

/* Timer1 para mouse click debounce */
#define mouse_move_tim        Timer1

/* Joystick pinout */
#define JOYSTICK_X_POS_PIN    A0
#define JOYSTICK_Y_POS_PIN    A3
#define JOYSTICK_BUTTON_PIN   (3)
#define LED_PIN               (13)

/* Remueve el offset del joystick */
#define REMOVE_OFFSET         (8)
#define MOVE_SENSITIVITY      (120)
#define SCREEN_WIDTH          (1920)
#define SCREEN_HEIGHT         (1080)

#define CLICK_RELEASE         (0)
#define LEFT_CLICK            (1 << 0)
/*#define RIGHT_CLICK           (1 << 1)*/
#define RIGHT_CLICK           (1 << 0)        /*Por conveniencia: asignamos al LEFT_CLICK*/
#define SCROLL_CLICK          (1 << 2)

#define MOVE_PERIOD           (16)
#define DEBOUNCE_TIMER        (200)
#define RELEASE_TIMER         (200)
#define MOUSE_BUFF_LEN        (7)

#define OFFSET_MEASURED       (530)
#define MAP_OFFSET(X)         (((X - OFFSET_MEASURED) * 0.25) / REMOVE_OFFSET)

#define MIN_VAL               (((-OFFSET_MEASURED) * 0.25) / REMOVE_OFFSET)
#define MAX_VAL               (((1023 - OFFSET_MEASURED) * 0.25) / REMOVE_OFFSET)

#define MAP_SCREEN_X(X)       (map(X, \
                              MIN_VAL, \
                              MAX_VAL, \
                              -SCREEN_WIDTH / MOVE_SENSITIVITY, \
                              SCREEN_WIDTH / MOVE_SENSITIVITY))

#define MAP_SCREEN_Y(Y)       (map(Y, \
                              MIN_VAL, \
                              MAX_VAL, \
                              -SCREEN_HEIGHT / MOVE_SENSITIVITY, \
                              SCREEN_HEIGHT / MOVE_SENSITIVITY))

typedef enum
{
  INIT = 0,
  PRESSED,
  BOUNCING,
  RELEASED,
} click_pressed_t;

volatile uint8_t isr_click_flag  = 0;
volatile click_pressed_t click_pressed_flag = INIT;

int8_t x_pos = 0;
int8_t y_pos = 0;

volatile int x_value = 0;
volatile int y_value = 0;

volatile uint16_t x_adc_value_isr = 0;
volatile uint16_t y_adc_value_isr = 0;

volatile uint8_t move_mouse = 0;
uint8_t click_holder = CLICK_RELEASE;

volatile uint32_t debounce_timer = 0;
volatile uint32_t release_timer = 0;
volatile uint32_t move_timer = 0;
uint8_t mouse_buff[MOUSE_BUFF_LEN];

ADC *adc = new ADC();

void joystick_irq_cb(void)
{
  isr_click_flag = 1;
}

void mouse_move_cb(void)
{
  move_mouse = 1;
}

void adc0_isr(void)
{
  x_adc_value_isr = adc->analogReadContinuous(ADC_0);
}

void adc1_isr(void)
{
  y_adc_value_isr = adc->analogReadContinuous(ADC_1);
}

void mouse_map_var(volatile uint16_t * x_var_in, volatile uint16_t * y_var_in, int8_t * x_var_out, int8_t * y_var_out)
{
  #if 0
    x_pos = (int)(x_value - 522) * 0.25 / REMOVE_OFFSET;
    y_pos = (int)(y_value - 521) * 0.25 / REMOVE_OFFSET;

    x_pos = (x_pos < -127) ? -127 : x_pos;
    y_pos = (y_pos < -127) ? -127 : y_pos;
  #else
    int16_t x_pos_temp = *x_var_in;
    int16_t y_pos_temp = *y_var_in;

    x_pos_temp = MAP_OFFSET(x_pos_temp);
    y_pos_temp = MAP_OFFSET(y_pos_temp);

    *x_var_out = MAP_SCREEN_X(x_pos_temp);
    *y_var_out = MAP_SCREEN_Y(y_pos_temp);
  #endif
}

void mouse_move_handler(void)
{
  if (millis() - move_timer > MOVE_PERIOD)
  {
    move_timer = millis();
    
    mouse_map_var(&x_adc_value_isr, &y_adc_value_isr, &x_pos, &y_pos);

    if ((Bluetooth_Serial.availableForWrite() > MOUSE_BUFF_LEN) && ((x_pos != 0) || (y_pos != 0)))
    {
      mouse_move(x_pos, -y_pos, click_holder);
    }
  }
}

void click_handler(void)
{
  /* Detección de tecla pulsada */
  if ((click_pressed_flag == INIT) && isr_click_flag)
  {
    click_pressed_flag = BOUNCING;
    isr_click_flag = 0;

    digitalWrite(LED_PIN, HIGH);

    click_holder = RIGHT_CLICK;
    mouse_move(0, 0, click_holder);
    // SERIAL_DBG.print("pressed...\r\n");

    debounce_timer = millis();
  }

  if ((click_pressed_flag == BOUNCING) && (millis() - debounce_timer > DEBOUNCE_TIMER))
  {
    debounce_timer = millis();
    isr_click_flag = 0;

    /* HIGH = boton no presionado */
    if (digitalRead(JOYSTICK_BUTTON_PIN))
    {
      click_pressed_flag = RELEASED;

      digitalWrite(LED_PIN, LOW);

      click_holder = CLICK_RELEASE;
      mouse_move(0, 0, click_holder);
      // SERIAL_DBG.print("released...\r\n");
      release_timer = millis();
    }
  }

  if ((click_pressed_flag == RELEASED) && (millis() - release_timer > RELEASE_TIMER))
  {
    // SERIAL_DBG.print("reinit...\r\n");
    click_pressed_flag = INIT;
    isr_click_flag = 0;
  }
}

void adc_init(void)
{
  /* 
    setConversionSpeed can be any of the ADC_CONVERSION_SPEED enum: VERY_LOW_SPEED, LOW_SPEED, MED_SPEED, HIGH_SPEED_16BITS, HIGH_SPEED or VERY_HIGH_SPEED
    see the documentation for more information
    additionally the conversion speed can also be ADACK_2_4, ADACK_4_0, ADACK_5_2 and ADACK_6_2,
    where the numbers are the frequency of the ADC clock in MHz and are independent on the bus speed

    setSamplingSpeed can be any of the 
    ADC_MED_SPEED enum: VERY_LOW_SPEED, LOW_SPEED, MED_SPEED, HIGH_SPEED or VERY_HIGH_SPEED
  */

  /* Set number of averages */
  adc->setAveraging(8, ADC_0);

  /* Set bits of resolution */
  adc->setResolution(10, ADC_0);

  /* Change the conversion speed */
  adc->setConversionSpeed(ADC_CONVERSION_SPEED::HIGH_SPEED, ADC_0);

  /* Change the sampling speed */
  adc->setSamplingSpeed(ADC_SAMPLING_SPEED::HIGH_SPEED, ADC_0);

  /* Enable interrupts */
  adc->enableInterrupts(ADC_0);

  /* Set number of averages */
  adc->setAveraging(8, ADC_1);

  /* Set bits of resolution */
  adc->setResolution(10, ADC_1);

  /* Change the conversion speed */
  adc->setConversionSpeed(ADC_CONVERSION_SPEED::HIGH_SPEED, ADC_1);

  /* Change the sampling speed */
  adc->setSamplingSpeed(ADC_SAMPLING_SPEED::HIGH_SPEED, ADC_1);

  /* Enable interrupts */
  adc->enableInterrupts(ADC_1);
}

void start_adc_conversion(void)
{
  adc->startContinuous(JOYSTICK_X_POS_PIN, ADC_0);
  adc->startContinuous(JOYSTICK_Y_POS_PIN, ADC_1);

  delay(500);
}

void init_mouse_buffer(void)
{
  memset(mouse_buff, 0, MOUSE_BUFF_LEN);

  mouse_buff[0] = 0xFD; //Inicio reporte HID
  mouse_buff[1] = 0x05; //Longitud de la trama
  mouse_buff[2] = 0x02; //Indica que es un mouse
}

void setup()
{
  /* UART inicializacion */
  SERIAL_DBG.begin(115200);
  Bluetooth_Serial.begin(115200);

  /* GPIO init */
  pinMode(JOYSTICK_BUTTON_PIN, INPUT_PULLUP);
  pinMode(JOYSTICK_X_POS_PIN, INPUT);
  pinMode(JOYSTICK_Y_POS_PIN, INPUT);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  /* Configuracion del modo de operacion Bluetooth RN-42 */
  //Bluetooth_Configure();

  /* Attach Joystick click interrupt */
  attachInterrupt(digitalPinToInterrupt(JOYSTICK_BUTTON_PIN), joystick_irq_cb, FALLING);
  
  /* Init ADC */
  adc_init();
  start_adc_conversion();

  /* Inicializa el temporizador */
  move_timer = millis();

  /* Inicializa buff mouse */
  init_mouse_buffer();

  /* Habilitar Interrupciones */
  sei();
}

void loop()
{
  click_handler();
  mouse_move_handler();
}
