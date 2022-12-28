void CalcularVarianzaAccel(int datos) {
  varianza_XAcel = 0;
  varianza_YAcel = 0;
  varianza_ZAcel = 0;
  
  for (int k = 0; k <= datos; k++) {
     varianza_XAcel += pow((XAcel_filtro[k] - media_XAcel), 2) ;
     varianza_YAcel += pow((YAcel_filtro[k] - media_YAcel), 2) ;
     varianza_ZAcel += pow((ZAcel_filtro[k] - media_ZAcel), 2) ;
     
  }
varianza_XAcel = varianza_XAcel/datos;  
varianza_YAcel = varianza_YAcel/datos;  
varianza_ZAcel = varianza_ZAcel/datos;  
}

