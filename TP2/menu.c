#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu()
{
  int choix;

  printf("\n***** Menu ****\n");
  printf("1 : Pour ajouter N spectacle \n");
  printf("2 : Pour modifier N d'acteur a un spectacle\n");
  printf("3 : Pour afficher les spectacles d'un theme donne \n");
  printf("4 : Pour afficher les acteurs d'un spectacle d'un titre donne\n");
  printf("5 : Pour afficher les spectacles auxquels un acteur a participé\n");
  printf("6 : Pour supprimer un spectacle \n");
  printf("6 : Pour modifier la listes des acteurs d'un spectacle \n");
  printf("7 : Exporter \n");
  printf("8 : Importer \n");
  printf("9 : Pour quitter le programme \n\n");

  do
  {
    printf("Saisr votre choix [1-9] : ");
    scanf("%d", &choix);
  } while (choix < 1 || choix > 9);

  return choix;
}
