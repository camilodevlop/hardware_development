/* Defines */
/* Puerto serial para la comunicacion con el modulo bluetooth */
#define Bluetooth_Serial    Serial1

/* Puerto serial para depurar */
#define SERIAL_DBG          SerialUSB

/* Keyboard defines */
#define NUM_COLUMNS   9
#define column_1      9
#define column_2      8
#define column_3      A1
#define column_4      4
#define column_5      5
#define column_6      A3
#define column_7      6
#define column_8      A2
#define column_9      7


#define NUM_ROWS      2
#define row_1         12
#define row_2         13


/* Puerto para LED de depuracion */
//#define PIN_LED       13

/* Variables globales */
byte iRow = 0, iCol = 0;
const unsigned long PERIOD = 200;
unsigned long debounce_timer = 0;
 
const byte countRows = NUM_ROWS;
const byte countColumns = NUM_COLUMNS;
 
const byte columnsPins[countColumns] = 
  {
    column_1,
    column_2,
    column_3,
    column_4,
    column_5,
    column_6,
    column_7,
    column_8,
    column_9
  };

const byte rowsPins[countRows] = 
  {
    row_1,
    row_2
  };
 
const int keys[countRows][countColumns] = {
  { 1, 2, 3, 4, 5, 6, 7, 8, 9},
  { 10, 11, 12, 13, 14, 15, 16, 17, 18}
  };

/* Leer el estado del teclado */
bool readKeypad()
{
  bool rst = false;

  /* Barrido de columnas */
  for (byte c = 0; c < countColumns; c++)
  {
    /* Poner columna a LOW */
    pinMode(columnsPins[c], OUTPUT);
    digitalWrite(columnsPins[c], LOW);
    
    /* Barrer todas las filas comprobando pulsaciones */
    for (byte r = 0; r < countRows; r++)
    {
      /* if (digitalRead(columnsPins[c]) == LOW) */
      if (digitalRead(rowsPins[r]) == LOW)
      {
        // Pulsacion detectada, guardar fila y columna
        iRow = r;
        iCol = c;
        rst = true;
      }
    }

    /* Devolver la columna a alta impedancia */
    digitalWrite(columnsPins[c], HIGH);
    //pinMode(columnsPins[c], INPUT);
  }

  return rst;
}

void setup()
{
  SERIAL_DBG.begin(57600);
  Bluetooth_Serial.begin(115200);

  /* Configuracion del modo de operacion Bluetooth RN-42 */
  //Bluetooth_Configure();

  /* Debug */
  //pinMode(PIN_LED, OUTPUT);

  // Columnas en alta impedancia
  for (byte c = 0; c < countColumns; c++)
  {
    pinMode(columnsPins[c], INPUT);
    digitalWrite(columnsPins[c], HIGH);
  }
 
  /* Filas en pullup */
  for (byte r = 0; r < countRows; r++)
  {
    pinMode(rowsPins[r], INPUT_PULLUP);
  }
}
 
void loop()
{
  static byte debounce_flag = 1;

  /* Detección de tecla pulsada */
  if (debounce_flag && readKeypad())
  {
    debounce_flag = 0;

     if (keys[iRow][iCol] == 10)
    {
     func_mouse((1<<0), 0,0, -0x00);    //Clic izquierdo.
     delay(100);
     func_mouse(0x0, 0,0, 0x00);
     debounce_timer = millis();
    }

    if (keys[iRow][iCol] == 11)
    {
     func_mouse((1<<1), 0,0, -0x00);    //Clic izquierdo.
     delay(100);
     func_mouse(0x0, 0,0, 0x00);
     debounce_timer = millis();
    }

    if (keys[iRow][iCol] == 12)
    {
     func_mouse(0x00, 0,0, -0x02);    // Scroll down.
     delay(100);
     func_mouse(0x0, 0,0, 0x00);
     debounce_timer = millis();
    }

    if (keys[iRow][iCol] == 13)
    {
     func_mouse(0x00, 0,0, 0x02);    // Scroll up
     delay(100);
     func_mouse(0x0, 0,0, 0x00);
     debounce_timer = millis();
    }

    if (keys[iRow][iCol] == 14)
    {
    press_key2(0x01, 0x06);   // Presiona Ctrl + C.
    delay(100);
    press_key2(0x00, 0x00);   // Ctrl release.
      debounce_timer = millis();
    }

    if (keys[iRow][iCol] == 15)
    {
    press_key2(0x01, 0x19);   // Presiona Ctrl + V.
    delay(100);
    press_key2(0x00, 0x00);   // Ctrl release.
      debounce_timer = millis();
    }

    if (keys[iRow][iCol] == 16)
    {
    press_key2(0x01, 0x1B);   // Presiona Ctrl + X.
    delay(100);
    press_key2(0x00, 0x00);   // Ctrl release.
      debounce_timer = millis();
    }

    if (keys[iRow][iCol] == 17)
    {
    press_key2(0x01, 0x13);   // Presiona Ctrl + P.
    delay(100);
    press_key2(0x00, 0x00);   // Ctrl release.
    debounce_timer = millis();
    }

    if (keys[iRow][iCol] == 18)
    {
      press_key2(0x05, 0x4C);   // Presiona Ctrl + Alt + Supr.
      delay(100);
      press_key2(0x00, 0x00);   // Ctrl release.
      debounce_timer = millis();
    }
  }

  /* Debounce */
  if (!debounce_flag && millis() - debounce_timer > PERIOD)
  {
    debounce_flag = 1;
    //digitalWrite(PIN_LED, LOW);
  }
}
