uint16_t LeerRegistro(char Dir_Dispositivo, char Dir_Inicio, int Num_Datos, int Buffer[6])
{
  Wire.beginTransmission(Dir_Dispositivo);  // Dirección del registro de donde se tomarán los datos.
  Wire.write(Dir_Inicio);
  Wire.endTransmission();

  Wire.beginTransmission(Dir_Dispositivo);
  Wire.requestFrom(Dir_Dispositivo, Num_Datos); // 1 corresponde al único byte que se requiere transmitir.

  int i = 0;
  while (Wire.available()) {
    Buffer[i] = Wire.read();
    i++;
  }
  Wire.endTransmission();
}
