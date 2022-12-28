void func_mouse(byte Click, byte BP_X, byte BP_Y, byte Scroll)
{
       Bluetooth_Serial.write((byte) 0xFD);          //Inicio reporte HID (Shorthand mode)
       Bluetooth_Serial.write((byte) 0x05);          //Longitud de la trama
       Bluetooth_Serial.write((byte) 0x02);          //Indica que es un mouse
       //Bluetooth_Serial.write((byte) 0x00);          //Modificador
       
       Bluetooth_Serial.write(Click);    //Boton presionado //(1<<2) scroll button, (1<<1) right button,  (1<<0) left button
       Bluetooth_Serial.write(BP_X);     //Rango (-127,127)
       Bluetooth_Serial.write(BP_Y);     //Rango (-127,127)
       Bluetooth_Serial.write(Scroll);     //Scroll
        
       //Bluetooth_Serial.write((byte) 0xFD);
       //Bluetooth_Serial.write((byte) 0x00);
}
