#include <stdio.h>
#include <string.h>
#include "classroom.h"

void remplissage(Etudiant *liste, int N)
{
  for (int i = 0; i < N; i++)
  {
    printf("**Etudiant %d\n", i + 1);
    printf("Nom: ");
    scanf("%s", (liste + i)->nom);

    printf("Prenom: ");
    scanf("%s", (liste + i)->prenom);

    for (int i = 0; i < 3; i++)
    {
      printf("Note %d: ", i + 1);
      scanf("%f", &(liste + i)->notes[i]);
    }

    float moy = 0;
    for (int i = 0; i < 3; i++)
    {
      moy += (liste + i)->notes[i];
    }
    (liste + i)->moyenne = moy / 3;
  }
}

void affichage(Etudiant *liste, int N)
{
  for (int i = 0; i < N; i++)
  {
    if ((liste + i)->moyenne > 10)
    {
      printf("**Etudiant %d\n", i + 1);
      printf("Moyenne: %.2f\n", (liste + i)->moyenne);
    }
  }
}

Etudiant search(Etudiant *liste, int N)
{
  char nom[20];
  char prenom[20];

  printf("============Search============\n");
  printf("Nom: ");
  scanf("%s", nom);
  printf("Prénom: ");
  scanf("%s", prenom);

  printf("============Search Result============\n");
  for (int i = 0; i < N; i++)
  {
    int nomCmp = strcmp((liste + i)->nom, nom);
    int prenomCmp = strcmp((liste + i)->prenom, prenom);

    if (nomCmp == 0 && prenomCmp == 0)
    {
      return *(liste + i);
    }
  }

  printf("NULL");
}
