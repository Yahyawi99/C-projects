#include <stdio.h>
#include "market.h"

int main()
{

  STR_market myMarket;
  char CIN[] = "BK688337";

  build_market(&myMarket, 1);

  affichage(myMarket);

  modification(&myMarket, 1175);

  afficher_historique(myMarket, CIN);

  return 0;
}