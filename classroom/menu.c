#include <stdio.h>
#include <string.h>
#include "menu.h"

int menu()
{
  int choix;

  printf("============Menu============\n");
  printf("Choisie entre les choix suivant: \n");
  printf("1-Afficher\n");
  printf("2-Search\n");
  printf("Appuyez sur n'importe quelle touche pour quitter\n");

  scanf("%d", &choix);

  return choix;
}