void Filtro_MediaMovil(float orden)
{
  for (int k = 0; k <= orden; k++) {
    auxFiltro_XAcel[k] = XAcel_filtro[k];
    auxFiltro_YAcel[k] = YAcel_filtro[k];
    auxFiltro_ZAcel[k] = ZAcel_filtro[k];
    auxFiltro_ZGiro[k] = ZGiro_filtro[k];
    auxFiltro_XGiro[k] = XGiro_filtro[k];
  }

  media_XAcel = ax;
  media_YAcel = ay;
  media_ZAcel = az;
  media_ZGiro = gz;
  media_XGiro = gx;

  for (int k = 0; k <= (orden ); k++) {
    XAcel_filtro[k + 1] = auxFiltro_XAcel[k];
    YAcel_filtro[k + 1] = auxFiltro_YAcel[k];
    ZAcel_filtro[k + 1] = auxFiltro_ZAcel[k];
    media_XAcel = media_XAcel + XAcel_filtro[k + 1];
    media_YAcel = media_YAcel + YAcel_filtro[k + 1];
    media_ZAcel = media_ZAcel + ZAcel_filtro[k + 1];

  }
  for (int k = 0; k <= (orden ); k++) {
    XGiro_filtro[k + 1] = auxFiltro_XGiro[k];
    ZGiro_filtro[k + 1] = auxFiltro_ZGiro[k];
    media_XGiro = media_XGiro + XGiro_filtro[k + 1];
    media_ZGiro = media_ZGiro + ZGiro_filtro[k + 1];
  }

  XAcel_filtro[0] = ax;
  YAcel_filtro[0] = ay;
  ZAcel_filtro[0] = az;
  XGiro_filtro[0] = gx;
  ZGiro_filtro[0] = gz;

  media_XAcel = media_XAcel / orden;
  media_YAcel = media_YAcel / orden;
  media_ZAcel = media_ZAcel / orden;
  media_ZGiro = media_ZGiro / orden;
  media_XGiro = media_XGiro / orden;
}
