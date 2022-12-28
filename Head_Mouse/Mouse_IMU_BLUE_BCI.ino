//#include <TimerOne.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#define LED_PIN 53
//-------------------------------------------------------
//Declaracion para el bluetooth
//SoftwareSerial bluetooth(9, 8); //RX TX
SoftwareSerial mySerial(10, 11); //RX, TX

// DeclaraciÃ³n de sensores.d
// DirecciÃ³n de sensores.
#define DIR_ACCEL ((char) 0x53) // 0x53 = 0xA6 / 2
#define DIR_GYRO  ((char) 0x68) // 0x68

//-------------------------------------------------------

// Variables y Arreglos
float ax, ay, az;                               // Muestras AcelerÃ³metro.
float gx, gy, gz;                               // Muestras del Giroscopio.
float mx, my, mz;                               // Muestras MagnetÃ³metro.

// Envio de datos
String Datos;
String Angulos;

//-------------------------------------------------------

// Variables para las funciones de movimiento del mouse.***********************************************************************************
// CaracterÃ­sticas de la pantalla.
float Sensibilidad_Desplazamiento = 1;
int width = 1366;
int height = 768;

// Para sony vaio -> mouseMove(1,0) 2.75 px -> 0.624mm
float resolution = 5.53; // px/mm para 1366x768
float pix_med = 1 / resolution;

// Movimiento del Mouse
int16_t lecturaX;
int16_t lecturaY;
float move_X, move_Y;

int RetardoRespuesta = 10;
int16_t temperatura;

// Variables para clic
int16_t deltaGiroY;
int16_t LecturaGiroYactual;
int16_t LecturaGiroYanterior = 0;
double AccelMag = 0;

int corrx = 1;
int bandera2 = 0;

volatile int bandera;

// Variables filtro media mÃ³vil
int orden = 30;

// Velocidad angular
float ZGiro_filtro[40];
float auxFiltro_ZGiro[40];
float media_ZGiro = 0;

float XGiro_filtro[40];
float auxFiltro_XGiro[40];
float media_XGiro = 0;

// AceleraciÃ³n
float XAcel_filtro[40];
float auxFiltro_XAcel[40];
float media_XAcel = 0;
double varianza_XAcel = 0;

float YAcel_filtro[40];
float auxFiltro_YAcel[40];
float  media_YAcel = 0;
double varianza_YAcel = 0;

float ZAcel_filtro[40];
float  auxFiltro_ZAcel[40];
float  media_ZAcel = 0;
double varianza_ZAcel = 0;

float Var_ActX;
float Var_ActY;
float Var_ActZ;

//Bandera para detectar los eventos.
int bandera_eventos = 0;

//-------------------------------------------------------
bool blinkState = false;

//Variables de tiempo
long dt, t_anterior;

//Variables para angulos
float A_x = 0, A_z = 0;
byte h = 40; //40 cm
int k = 0;

//-----------------------------------------------------------
// checksum variables
byte payloadChecksum = 0;
byte CalculatedChecksum;
byte checksum = 0;              //data type byte stores an 8-bit unsigned number, from 0 to 255
int payloadLength = 0;
byte payloadData[64] = {0};
int rawValue = 0;

// system variables
long lastReceivedPacket = 0;
boolean bigPacket = false;
boolean brainwave = false;

//Filter outputs
float output = 0.0;
float output2 = 0.0;
float output3 = 0.0;
float output4 = 0.0;
float output5 = 0.0;
float output6 = 0.0;
float output7 = 0.0;

byte contador = 0;
float outputx = 0;
byte contador2 = 0;
float outputx2 = 0;
float outputx3 = 0;
float Outputx = 0;

float Output = 0.0;
float Output2 = 0.0;
float Output3 = 0.0;
float Output4 = 0.0;

float anterior = 0;

//Contadores para interrupciones
byte imu = 0;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  Serial1.begin(57600);
  mySerial.begin(9600); //Inicializa el bluetooth

  Wire.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(4 , OUTPUT);  //definir pin como salida
  pinMode(5, OUTPUT);  //definir pin como salida
  pinMode(LED_PIN, OUTPUT);
  //****************************************************************************************************************************************************************
  // Configuración de temporizador para interrupciones.
  cli();  //Deshabilitar las interrupciones globales para evitar errores en el setup.
  TCCR3A = 0;
  TCCR3B = 0;
  TCNT3 = 0;

  TCCR3A = (1 << COM3A0); // Activo el canal 1 para comparación (Timer)
  TCCR3B = (1 << WGM32);  // Establezco el modo CTC
  //TCCR3B = (1 << WGM12);  // Establezco el modo CTC //--Modificacion
  //TCCR3B |= (1 << CS31); TCCR3B |= (1 << CS30);   // Prescaler de 64
  TCCR3B |= (1 << CS32);   // Prescaler de 256

  //OCR3A = 124; // 1ms con un prescaler de 64
  //OCR3A = 15624; // 500ms con un prescaler de 256
  //OCR3A = 31249; // 1s con un prescaler de 256
  //OCR3A = 156; // 5ms con un prescaler de 256
  //OCR3A = 624; // 20ms con un prescaler de 256
  //OCR3A = 937; // 30ms con un prescaler de 256
    OCR3A = 1249; // 40ms con un prescaler de 256
  //OCR3A = 1562; // 50ms con un prescaler de 256

  TIMSK3 = (1 << OCIE3A);

  //UCSR1B |= (1 << RXCIE1);  //sets RXCIE0 in register UCSR0B to 1, to enable USART reception interrupt.
  //UCSR1B |= ((1 << RXEN1) | (1 << RXCIE1)); //Enable Receiver and Interrupt RX

  sei(); //Habilitar interrupciones
  // Fin configuración de temporizador para interrupciones
  //**********************************************************************IMU***************************************************************************************
  // Acelerómetro
  // Asignar un rango de +/- 4G. // Rango: 0 = 2g, 1 = 4g, 2 = 8g, 3 = 16g. En binario: 00 = 2g, 01 = 4g, 10 = 8g, 11 = 16g. // Registro: DATA_FORMAT = 0x31.
  EscribirRegistro(DIR_ACCEL, 0x31, 0);
  // Registro de Control de Energía // POWER_CTL
  EscribirRegistro(DIR_ACCEL, 0x2D, 0x08);
  // Registro de Control de Energía // DATA_RATE
  EscribirRegistro(DIR_ACCEL, 0x2C, 0x0C);

  // Giroscopio
  // Registro de Escala del sensor y Frecuencia de Corte filtro pasa bajas
  // DLPF, Full Scale
  EscribirRegistro(DIR_GYRO, 0x16, 0x1E);
  // Frecuencia de Muestreo // SMPLRT_DIV
  EscribirRegistro(DIR_GYRO, 0x15, 0x07);
  //****************************************************************************************************************************************************************
}

byte ReadOneByte() {
  int ByteRead;
  while (!Serial1.available());
  ByteRead = Serial1.read();
  //Serial.println(ByteRead, HEX);
  return ByteRead; // read incoming serial data
}

void RecData() {
  // Look for sync bytes
  // Byte order: 0xAA, 0xAA, payloadLength, payloadData,
  // Checksum (sum all the bytes of payload, take lowest 8 bits, then bit inverse on lowest
  if (ReadOneByte() == 0xAA) {
    if (ReadOneByte() == 0xAA) {
      payloadLength = ReadOneByte();
      if (payloadLength > 169) //Payload length can not be greater than 169
        return;
      payloadChecksum = 0;
      for (int i = 0; i < payloadLength; i++) {     //loop until payload length is complete
        payloadData[i] = ReadOneByte();             //Read payload
        payloadChecksum += payloadData[i];
      }
      checksum = ReadOneByte();                     //Read checksum byte from stream
      payloadChecksum = 255 - payloadChecksum;      //Take one’s compliment of generated checksum
      if (checksum == payloadChecksum) {
        rawValue = 0;
      }
      brainwave = false;
      for (int i = 0; i < payloadLength; i++) { // Parse the payload
        switch (payloadData[i]) {
          case 02:
            i++;
            bigPacket = true;
            break;
          case 04:
            i++;
            break;
          case 05:
            i++;
            break;
          case 0x06:
            i++;
            break;
          case 0x80:
            i++;//-------------------------------------------------13
            rawValue = ((int)payloadData[++i] << 8) | payloadData[++i];
            if (rawValue > 32768) {
              rawValue = rawValue - 65536;//Modificacion
            }
            break;
          case 0x83:                         // ASIC EEG POWER INT
            i = i + 25;
            break;
        }                                 // switch
      }                                   // for loop
    }
  }
}

void RecData2() {
  int r1, r2;
  if (ReadOneByte() == 0xAA) {
    if (ReadOneByte() == 0xAA) {
      if (ReadOneByte() == 0x04) {
        if (ReadOneByte() == 0x80) {
          if (ReadOneByte() == 0x02) {
            r1 = ReadOneByte();
            r2 = ReadOneByte();
            rawValue = ((int)r1 << 8) | r2;
            if (rawValue > 32768) {
              rawValue = rawValue - 65536;
            }
          }
        }
      }
    }
  }
}

void filter() {
  output = 0.1155 * rawValue + 0.8845 * output; //fc = 10; Fs = 512
  output2 =  0.1155 * output + 0.8845 * output2;
  output3 =  0.1155 * output2 + 0.8845 * output3;
  output4 =  0.1155 * output3 + 0.8845 * output4;

  outputx += output2;
  ++contador;
  if (contador == 10) { //Con contador = 10
    contador = 0;
    outputx /= 10;
  }

  Output = 0.1155 * outputx + 0.8845 * Output; //fc = 10; Fs = 512
  Output2 =  0.1155 * Output + 0.8845 * Output2;
  Output3 =  0.1155 * Output2 + 0.8845 * Output3;
  Output4 =  0.1155 * Output3 + 0.8845 * Output4;

  Serial.println(Output4);
//      Serial.print(" ");
//      Serial.print(6000);
//      Serial.print(" ");
//      Serial.print(" ");
//      Serial.print(1500);
//      Serial.print(" ");
//      Serial.print(-1500);
//      Serial.print(" ");
//      Serial.println(-6000);

  //Serial.print(", ");
  //Serial.println(mySerial.available());
  if (Serial1.available() >= 62) {//62
    Serial1.end();
    Serial1.begin(57600);
  }
}

void LED() {
  if (Output4 < -1500 && Output4 > -3000 && (anterior < Output4)) {
    digitalWrite(4 , HIGH);   // poner el Pin en HIGH
  }
  else {
    digitalWrite(4 , LOW);   // poner el Pin en LOW
  }

  //t_anterior = micros();

  if (Output4 < -1500 && Output4 > -3000 && (anterior > Output4)) {
    digitalWrite(5 , HIGH);   // poner el Pin en HIGH
  }
  else {
    digitalWrite(5 , LOW);   // poner el Pin en LOW
  }
}

void IMU() {
  LeerSensor(DIR_ACCEL, 6);
  LeerSensor(DIR_GYRO, 6);

  AccelMag = sqrt(ay * ay + az * az + ax * ax);
  Filtro_MediaMovil(20);
  CalcularVarianzaAccel(20);

  Var_ActX = 0.0002; Var_ActY = 0.0002; Var_ActZ = 0.0002;

  if (varianza_XAcel < Var_ActX && varianza_YAcel < Var_ActY  ) {
    //   if (varianza_XAcel < 0.0001 && varianza_YAcel <0.001 &&  varianza_ZAcel <0.0027){
    bandera_eventos = 0;
    lecturaX = 0;
    lecturaY = 0;
  }

  if (varianza_XAcel >= Var_ActX ||  varianza_YAcel >= Var_ActY || varianza_ZAcel >= Var_ActZ)
  {
    bandera_eventos = 1;
  }

  if (bandera_eventos == 1)
  {
    lecturaX = map(media_ZGiro, -32728 / 14.375 * Sensibilidad_Desplazamiento, 32728 / 14.375 * Sensibilidad_Desplazamiento, -width / 2 , width / 2 );
    lecturaY = map(media_XGiro, -32728 / 14.375 * Sensibilidad_Desplazamiento, 32728 / 14.375 * Sensibilidad_Desplazamiento, -width / 2 , width / 2);

    move_X = ((lecturaX * 0.624) / pix_med) / 2.75;
    move_Y = ((lecturaY * 0.624) / pix_med) / 2.75;

    lecturaX = round(move_X);
    lecturaY = round(move_Y);

    mouseMove(lecturaX, lecturaY); //                                    1 -> 1px, 2 -> ~1px, 3 -> 2px, 4 -> 3px, 5 -> ~3 o 4px (para 1366, 768)

  }
}

void mouseMove(signed int BP_X, signed int BP_Y) {
  mySerial.write((byte)0xFD);  //Inicio reporte HID
  mySerial.write((byte)0x5);   //Longitud de la trama
  mySerial.write((byte)0x2);   //Indica que es un mouse
  mySerial.write((byte)0x00);  //Boton presionado
  mySerial.write(BP_X);        //(-127,127)
  mySerial.write(BP_Y);        //(-127,127)
  mySerial.write((byte)0x00);  //Envia un cero
}

void loop() {
  //*****************************CONTEO DE TIEMPO*************************************
//    dt = millis() - t_anterior;
//    t_anterior = millis();
//    Serial.println(dt);
  //**********************************************************************************

  //ReadOneByte();
  RecData2();
  filter();
  if (imu == 1) {
    //UCSR1B = (0 << RXEN1)  | (0 << RXCIE1); //Deshabilita recepcion
    IMU();
    //delay(100);
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    imu = 0;
    //UCSR1B = (1 << RXEN1)  | (1 << RXCIE1); //Habilita recepcion
  }
}

ISR (TIMER3_COMPA_vect)  // Interrupción asociada al instante en que se completa el tiempo en alto de pwm.
{
  imu++;
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}
