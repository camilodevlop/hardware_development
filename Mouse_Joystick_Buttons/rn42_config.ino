void Bluetooth_Configure(void)
{
  byte Command_Delay_Time = 200;

  Bluetooth_Serial.write("$$$"); // Entrar en modo comando
  delay(Command_Delay_Time);

  Bluetooth_Serial.write("SN,Teensy_Joy_Mouse"); Bluetooth_Serial.print("\n");   // Establecer el nombre del dispositivo, por defecto RNBT-72AC
  delay(Command_Delay_Time);

  Bluetooth_Serial.write("SX,1"); Bluetooth_Serial.print("\n");    // Activar "bonding" (1: solo se conecta a la direccion almacenada)
  delay(Command_Delay_Time);

  Bluetooth_Serial.write("SA,0"); Bluetooth_Serial.print("\n");    // Establecer modo de autenticacion: Sin seguridad
  delay(Command_Delay_Time);

  Bluetooth_Serial.write("SU,11"); Bluetooth_Serial.print("\n");    // Establecer tasa de baudios a 115200.
  delay(Command_Delay_Time);

  // Bluetooth_Serial.write("SQ,16"); Bluetooth_Serial.print("\n");     // This option configures the firmware to optimize for low latency data transfers rather than throughput.
  // delay(Command_Delay_Time);
  
  //Bluetooth_Serial.write("SM,1"); Bluetooth_Seria l.print("\n");   // Establecer modo maestro - ExtracciÃ³n de datos.

  Bluetooth_Serial.write("SM,6"); Bluetooth_Serial.print("\n");     // Establecer modo paridad.
  delay(Command_Delay_Time);

  Bluetooth_Serial.write("S~,6"); Bluetooth_Serial.print("\n");     // Establecer modo HID.
  //Bluetooth_Serial.write("S~,0"); Bluetooth_Serial.print("\n");     // Establecer modo por defecto, sin control de modem - ExtracciÃ³n de datos.
  delay(Command_Delay_Time);

  // Bluetooth_Serial.write("SP,47641"); Bluetooth_Serial.print("\n");  // Pone el pin de seguridad.
  // delay(Command_Delay_Time);

  Bluetooth_Serial.write("SH,0220"); Bluetooth_Serial.print("\n");  // Establecer dispositivo como mouse
  // Bluetooth_Serial.write("SH,0200"); Bluetooth_Serial.print("\n");  // Establecer dispositivo como keyboard
  // Bluetooth_Serial.write("SH,0230"); Bluetooth_Serial.print("\n");  // Establecer dispositivo como keyboard
  delay(Command_Delay_Time);

  //  Bluetooth_Serial.write("SR,14ABC51F20F6"); Bluetooth_Serial.print("\n");    // Almacenar direccion de dispositivo: DELL pc
  //Bluetooth_Serial.write("SR,28E34795D83D"); Bluetooth_Serial.print("\n");    // Almacenar direccion de dispositivo: Acer MarÃ­a
  //Bluetooth_Serial.write("SR,20C9D08555C6"); Bluetooth_Serial.print("\n");    // Almacenar direccion de dispositivo MAC Camilo
  //Bluetooth_Serial.write("SR,5800E3BD381A"); Bluetooth_Serial.print("\n");    // Almacenar direccion de dispositivo: Lenovo E-SPPB
  // Bluetooth_Serial.write("SR,0015830CBFEB"); Bluetooth_Serial.print("\n");  // Almacenar direccion de dispositivo: DG40S
  
  Bluetooth_Serial.write("SR,0006668672AC"); Bluetooth_Serial.print("\n");  // Almacenar direccion de dispositivo: receptor generico
  // Bluetooth_Serial.write("SR,D89C674DA768"); Bluetooth_Serial.print("\n");    // Almacenar direccion de dispositivo: David pc
  // Bluetooth_Serial.write("SR,68A74D679CD8"); Bluetooth_Serial.print("\n");    // Almacenar direccion de dispositivo: David pc
  
  // Bluetooth_Serial.write("SR,2CFDA1265C16"); Bluetooth_Serial.print("\n");    // Almacenar direccion de dispositivo: David cell
  delay(Command_Delay_Time);

  //Bluetooth_Serial.write("SW,007"); Bluetooth_Serial.print("\n");  // Sniff Mode: establecer encendido de dispositivo cada 4,38 ms para verificar si hay datos salida/ entrada.
  Bluetooth_Serial.write("SW,000"); Bluetooth_Serial.print("\n");  // Sniff Mode: deshabilitar.
  delay(Command_Delay_Time);

  Bluetooth_Serial.write("SY,FFFC"); Bluetooth_Serial.print("\n");  // Establecer potencia de transmisiÃ³n en 2 dBm de acuerdo con tabla antigua de potencia.
  delay(Command_Delay_Time);

  // Bluetooth_Serial.write("SF,1"); Bluetooth_Serial.print("\n");      // Reiniciar dispositivo de fabrica
  // delay(Command_Delay_Time);

  Bluetooth_Serial.write("R,1"); Bluetooth_Serial.print("\n");      // Reiniciar dispositivo para guardar configuraciones
  delay(1000);

  #if 1
    Bluetooth_Serial.write("$$$"); // Entrar en modo comando
    delay(Command_Delay_Time);

    // Bluetooth_Serial.write("C"); Bluetooth_Serial.print("\n");
    Bluetooth_Serial.write("CFR"); Bluetooth_Serial.print("\n"); //This command causes the device to connect and immediately go into fast data mode using the stored remote address.
    delay(5000);
  #endif
}
