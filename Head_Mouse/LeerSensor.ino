void LeerSensor(char Dir_Dispositivo, int Num_Datos) {
  int Buffer[6];
  if (Dir_Dispositivo == 0x53) { // Dirección del Acelerómetro
    const float Factor_Escala =  0.0039;
    const char Dir_Inicio = 0x32;

    LeerRegistro(Dir_Dispositivo, Dir_Inicio, Num_Datos, Buffer);

    ax = (((Buffer[1]) << 8) | Buffer[0]) * Factor_Escala;
    ay = (((Buffer[3]) << 8) | Buffer[2]) * Factor_Escala;
    az = (((Buffer[5]) << 8) | Buffer[4]) * Factor_Escala;
  }

  if (Dir_Dispositivo == 0x68) { // Dirección del Giroscopio
    const float Factor_Escala = 14.375;
    //const float Factor_Escala = 1;
    const char Dir_Inicio = 0x1D;

    LeerRegistro(Dir_Dispositivo, Dir_Inicio, Num_Datos, Buffer);

    gx = (((Buffer[0]) << 8) | Buffer[1]) / Factor_Escala;
    gy = (((Buffer[2]) << 8) | Buffer[3]) / Factor_Escala;
    gz = (((Buffer[4]) << 8) | Buffer[5]) / Factor_Escala;
  }
}

