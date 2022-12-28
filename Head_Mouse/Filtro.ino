void Filtro(int orden)
{
  for (int k = 0; k <= orden; k++) {
//    auxFiltro_Accel[k] = accelMag_filtro[k];
  }

//  accelMag_filtro[0] = ax;
  //media_Accel = ax;

  for (int k = 0; k <= orden - 1; k++) {
    //accelMag_filtro[k + 1] = auxFiltro_Accel[k];
  //  media_Accel = media_Accel + accelMag_filtro[k + 1];
  }

  //media_Accel = media_Accel/orden;
}
