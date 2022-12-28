#define SerialPort SerialUSB  // Puerto serial para la comunicación con el pc.
#define Bluetooth_Serial Serial2   // Puerto serial para la comunicación con el módulo bluetooth.

void setup() {
  SerialPort.begin(115200);
  Bluetooth_Serial.begin(115200);
  delay(500);

  // Configuracion del modulo RN-42 como HID-Mouse
    int Command_Delay_Time = 200;
  Bluetooth_Serial.write("$$$"); // Entrar en modo comando
  delay(Command_Delay_Time);
  Bluetooth_Serial.write("SN,WB_E-SPPB"); Bluetooth_Serial.print("\n");   // Establecer el nombre del dispositivo, por defecto RNBT-72AC
  delay(Command_Delay_Time);
  Bluetooth_Serial.write("SX,0"); Bluetooth_Serial.print("\n");    
  //Bluetooth_Serial.write("SX,1"); Bluetooth_Serial.print("\n");    // Activar "bonding" (solo se conecta a la direccion almacenada)
  delay(Command_Delay_Time);
  Bluetooth_Serial.write("SA,0"); Bluetooth_Serial.print("\n");    // Establecer modo de autenticacion: Sin seguridad
  delay(Command_Delay_Time);
  Bluetooth_Serial.write("SU,11"); Bluetooth_Serial.print("\n");    // Establecer tasa de baudios a 115200.
  delay(Command_Delay_Time);
  Bluetooth_Serial.write("SM,6"); Bluetooth_Serial.print("\n");     // Establecer modo paridad - Uso como dispositivo apuntador.
  //Bluetooth_Serial.write("SM,1"); Bluetooth_Serial.print("\n");   // Establecer modo maestro - Extracción de datos.
  delay(Command_Delay_Time);
  //Bluetooth_Serial.write("S~,6"); Bluetooth_Serial.print("\n");     // Establecer modo HID - Uso como dispositivo apuntador.
  Bluetooth_Serial.write("S~,0"); Bluetooth_Serial.print("\n");     // Establecer modo por defecto, sin control de modem - Extracción de datos.
  delay(Command_Delay_Time);
  //Bluetooth_Serial.write("SH,0220"); Bluetooth_Serial.print("\n");  // Establecer dispositivo como mouse
  //Bluetooth_Serial.write("SH,0230"); Bluetooth_Serial.print("\n");  // Establecer dispositivo como combo keyb-mouse
  delay(Command_Delay_Time);
  //Bluetooth_Serial.write("SR,14ABC51F20F6"); Bluetooth_Serial.print("\n");    // Almacenar direccion de dispositivo: DELL pc
  //Bluetooth_Serial.write("SR,28E34795D83D"); Bluetooth_Serial.print("\n");    // Almacenar direccion de dispositivo: Acer María
  //Bluetooth_Serial.write("SR,20C9D08555C6"); Bluetooth_Serial.print("\n");    // Almacenar direccion de dispositivo MAC Camilo
  //Bluetooth_Serial.write("SR,5800E3BD381A"); Bluetooth_Serial.print("\n");    // Almacenar direccion de dispositivo: Lenovo E-SPPB
  //Bluetooth_Serial.write("SR,001583ED50DA"); Bluetooth_Serial.print("\n");  // Almacenar direccion de dispositivo: receptor generico
  //Bluetooth_Serial.write("SR,000666DAD08E"); Bluetooth_Serial.print("\n");  // Almacenar direccion de dispositivo: receptor generico
  //Bluetooth_Serial.write("SR,0015830CBFEB"); Bluetooth_Serial.print("\n");  // Almacenar direccion de dispositivo: DG40S
  delay(Command_Delay_Time);
  //Bluetooth_Serial.write("SW,007"); Bluetooth_Serial.print("\n");  // Sniff Mode: establecer encendido de dispositivo cada 4,38 ms para verificar si hay datos salida/ entrada.
  Bluetooth_Serial.write("SW,000"); Bluetooth_Serial.print("\n");  // Sniff Mode: deshabilitar.
  delay(Command_Delay_Time);
  Bluetooth_Serial.write("SY,FFFC"); Bluetooth_Serial.print("\n");  // Establecer potencia de transmisión en 2 dBM de acuerdo con tabla antigua de potencia.
  delay(Command_Delay_Time);
  Bluetooth_Serial.write("R,1"); Bluetooth_Serial.print("\n");      // Reiniciar dispositivo para guardar configuraciones
  delay(3000);

  Bluetooth_Serial.write("$$$"); // Entrar en modo comando
  delay(Command_Delay_Time);
  //Bluetooth_Serial.write("C"); Bluetooth_Serial.print("\n");
  //Bluetooth_Serial.write("CFR"); Bluetooth_Serial.print("\n"); //This command causes the device to connect and immediately go into fast data mode using the stored remote address.
  delay(7000);

}

void loop() {
  if (SerialPort.available()) {
    Serial1.write(Serial.read());
  }

  if (Serial1.available()) {
    SerialPort.write(Serial1.read());
  }
}

/*Serial1.write("SU,57"); Serial1.print("\n");    // Establecer tasa de baudios a 57600
  delay(Command_Delay_Time);*/
/*Serial1.write("SF,1"); Serial1.print("\n");    // Valores de fábrica
  delay(Command_Delay_Time);*/
