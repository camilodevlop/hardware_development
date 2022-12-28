/* Defines */
/* Puerto serial para la comunicacion con el modulo bluetooth */
#define Bluetooth_Serial    Serial1

/* Puerto serial para depurar */
#define SERIAL_DBG          SerialUSB

/* Keyboard defines */
#define NUM_COLUMNS   3
#define column_1      9
#define column_2      8
#define column_3      A1


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
    column_3
  };

const byte rowsPins[countRows] = 
  {
    row_1,
    row_2
  };
 
const int keys[countRows][countColumns] = {
  { 1, 2, 3},
  { 4, 5, 6}
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

    //digitalWrite(PIN_LED, HIGH);
    //SERIAL_DBG.println(keys[iRow][iCol]);

    if (keys[iRow][iCol] == 1)
    {
      press_key2(0x05, 0x4C);   // Presiona Ctrl + Alt + Supr.
      delay(100);
      press_key2(0x00, 0x00);   // Ctrl release.
//    press_key2(0x01, 0x1B);   // Presiona Ctrl + x.
//    delay(100);
//    press_key2(0x00, 0x00);   // Ctrl release.
      debounce_timer = millis();
    }
    
    if (keys[iRow][iCol] == 2)
    {
     func_mouse(0x00, 0,0, 0x02);    // Scroll up
     delay(100);
     func_mouse(0x0, 0,0, 0x00);
     debounce_timer = millis();
    }
  
    if (keys[iRow][iCol] == 3)
    {
     func_mouse(0x00, 0,0, -0x02);    // Scroll down.
     delay(100);
     func_mouse(0x0, 0,0, 0x00);
     debounce_timer = millis();
    }
  
    if (keys[iRow][iCol] == 4)
    {
     //func_mouse(0x00, 0,0, -0x02);    // Scroll down.
     //func_mouse(0x00, 0,0, 0x02);    // Scroll up.
//     func_mouse((1<<0), 0,0, -0x00);    //Clic izquierdo.
//     delay(100);
//     func_mouse(0x0, 0,0, 0x00);
//     debounce_timer = millis();
    }
  
    if (keys[iRow][iCol] == 5)
    {
     func_mouse((1<<1), 0,0, -0x00);    //Clic derecho.
     delay(100);
     func_mouse(0x0, 0,0, 0x00);
     debounce_timer = millis();
    }

    if (keys[iRow][iCol] == 6)
    {
     func_mouse((1<<0), 0,0, -0x00);    //Clic izquierdo.
     delay(100);
     func_mouse(0x0, 0,0, 0x00);
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
