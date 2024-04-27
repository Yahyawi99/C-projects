#include <stdio.h>
#include "market.h"

int main()
{

  STR_market myMarket;
  char CIN[] = "BK688337";
  float ca;

  build_market(&myMarket, 1);

  affichage(myMarket);

  modification(&myMarket, 1175);

  afficher_historique(myMarket, CIN);

  ca = chiffre_affaire(myMarket, 112233);
  printf("%.2f\n", ca);

  suppression(&myMarket);

  return 0;
}