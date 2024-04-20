#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "menu.h"

int main()
{

  Biblio maBiblio;

  switch (menu())
  {
  case 1:
    maBiblio.nbrAdherants = 0;
    remplire_biblio(&maBiblio, 1);
    break;

  case 2:
    emprunter_livre(&maBiblio);
    break;

  case 3:
    afficher_adherants(&maBiblio);
    break;

  case 4:
    search(&maBiblio);
    break;

  case 5:
    retournez(&maBiblio);
    break;

  default:
    break;
  }

  return 0;
}