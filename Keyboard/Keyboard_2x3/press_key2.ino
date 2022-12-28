//void press_key2( byte input_key1)
void press_key2(byte mod, byte input_key)
{
       Bluetooth_Serial.write((byte) 0xFD);          //Inicio reporte HID (Shorthand mode)
       Bluetooth_Serial.write((byte) 0x09);          //Longitud de la trama
       Bluetooth_Serial.write((byte) 0x01);          //Indica que es un teclado
       Bluetooth_Serial.write((byte) mod);          //Modificador
       //Bluetooth_Serial.write((byte) 0x00);          // byte 0x00 
       
       Bluetooth_Serial.write((byte) 0x0);         // Key 1
       Bluetooth_Serial.write((byte) input_key);        // Key 2 
       Bluetooth_Serial.write((byte) 0x0);        // Key 3
       Bluetooth_Serial.write((byte) 0x0);
       Bluetooth_Serial.write((byte) 0x0);
       Bluetooth_Serial.write((byte) 0x0);
       Bluetooth_Serial.write((byte) 0x0);
       Bluetooth_Serial.write((byte) 0x0);
       Bluetooth_Serial.write((byte) 0x0);
}
