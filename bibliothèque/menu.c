#include <stdio.h>

int menu()
{
  int choix;
  printf("===========WELCOME===========\n");
  printf("La bibliothèque contenant plusieurs adhérents.\n");
  printf("Chaque adhérent a le droit d’emprunter au maximum 3 livres.\n");
  printf("Que voulez vous faire ?\n");

  printf("1- Saisir un certain nombre d’adhérent dans la bibliothèque.\n");
  printf("2- Emprunter un livre par un adhérent.\n");
  printf("3- Afficher tous les adhérents de la bibliothèque avec leurs livres empruntés.\n");
  printf("4- Afficher les informations sur les livres empruntés par un adhérent.\n");
  printf("5- Retourner un livre à la bibliothèque.\n");
  printf("==> ");

  scanf("%d", &choix);

  return choix;
}