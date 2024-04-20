#include <stdio.h>
#include <string.h>
#include "classroom.h"
#include "menu.h"

int main()
{
  int N;
  printf("Saisir le nombre d'etudiants: ");
  scanf("%d", &N);

  Etudiant liste[N];

  remplissage(liste, N);

  switch (menu())
  {
  case 1:
    affichage(liste, N);
    break;

  case 2:
    Etudiant etu = search(liste, N);
    printf("Moyenne : %.2f\n", etu.moyenne);
    break;

  default:
    return 0;
  }

  return 0;
}