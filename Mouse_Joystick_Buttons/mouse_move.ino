void mouse_move(int8_t BP_X, int8_t BP_Y, uint8_t Click)
{
  // mouse_buff[0] = 0xFD;
  // mouse_buff[1] = 0x05;
  // mouse_buff[2] = 0x02;
  mouse_buff[3] = Click;
  mouse_buff[4] = BP_X;
  mouse_buff[5] = BP_Y;
  // mouse_buff[6] = 0x00;

  #if 0
    Bluetooth_Serial.write(0xFD);     //Inicio reporte HID
    Bluetooth_Serial.write(0x05);     //Longitud de la trama
    Bluetooth_Serial.write(0x02);     //Indica que es un mouse
    Bluetooth_Serial.write(Click);    //Boton presionado //(1<<2) scroll button, (1<<1) right button,  (1<<0) left button
    Bluetooth_Serial.write(BP_X);     //Rango (-127,127)
    Bluetooth_Serial.write(BP_Y);     //Rango (-127,127)
    Bluetooth_Serial.write(0x00);     //Scroll
  #else
    Bluetooth_Serial.write(mouse_buff, MOUSE_BUFF_LEN);     //Scroll
  #endif
}
