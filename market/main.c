#include <stdio.h>
#include "market.h"

int main()
{

  STR_market myMarket;

  build_market(&myMarket, 1);
  affichage(myMarket);
  modification(&myMarket, 1175);

  return 0;
}