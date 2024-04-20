#include <stdio.h>
#include <string.h>
#include "utils.h"

// ======
void decalage(Livre tab[], int start, int n)
{
  for (int k = start; k < n - 1; k++)
  {
    tab[k] = tab[k + 1];
  }
}

// Saisir un certain nombre d’adhérent dans la bibliothèque.
Adherant cree_adherant()
{
  Adherant newAdherant;

  printf("Numéro(unique): ");
  scanf("%d", &newAdherant.numero);
  printf("Nom: ");
  scanf("%s", newAdherant.nom);

  newAdherant.nbrLivres = 0;

  return newAdherant;
}

void remplire_biblio(Biblio *maBiblio, int nbrOfNewAdherant)
{
  int N = maBiblio->nbrAdherants;

  if (N + nbrOfNewAdherant > 20)
  {
    printf("Vous avez atteint le maximum d'adhérent.");
    return;
  }

  for (int i = N; i < N + nbrOfNewAdherant; i++)
  {
    printf("=========Adherant %d=========\n", i + 1);
    maBiblio->adherants[i] = cree_adherant(i + 1);
  }

  maBiblio->nbrAdherants += nbrOfNewAdherant;
}

// Emprunter un livre par un adhérent.
void emprunter_livre(Biblio *maBiblio)
{

  int nbrOfAdherants = maBiblio->nbrAdherants;

  for (int i = 0; i < nbrOfAdherants; i++)
  {
    int nbrOfLivres = maBiblio->adherants[i].nbrLivres;

    if (nbrOfLivres > 3)
    {
      printf("Vous avez atteint le maximum de livres par adhérent.");
      return;
    }

    for (int j = nbrOfLivres; j < nbrOfLivres + 1; j++)
    {

      Livre newLivre;

      printf("**Livre %d:\n", j + 1);
      printf("Titre: ");
      scanf("%s", newLivre.titre);
      printf("Auteur: ");
      scanf("%s", newLivre.auteur);
      printf("Nombre des pages: ");
      scanf("%d", &newLivre.nbrPage);

      maBiblio->adherants[i].livres[j] = newLivre;
      maBiblio->adherants[i].nbrLivres++;
    }
  }
}

// search
void search(Biblio *maBiblio)
{
  char nom[20];
  printf("Saisir le nom d'adherant: ");
  scanf("%s", &nom);

  for (int i = 0; i < maBiblio->nbrAdherants; i++)
  {
    if (strcmp(maBiblio->adherants[i].nom, nom) == 0)
    {
      afficher_livres(maBiblio, i);
      return;
    }
  }

  printf("L'adherant avec le nom %s n'exuste pas.\n", nom);
}

// Retournez
void retournez(Biblio *maBiblio)
{
  char nom[20], titre[100];
  printf("Saisir le nom d'adherant: ");
  scanf("%s", &nom);

  printf("Saisir le titre de livre: ");
  scanf("%s", &titre);

  for (int i = 0; i < maBiblio->nbrAdherants; i++)
  {
    if (strcmp(maBiblio->adherants[i].nom, nom) == 0)
    {
      for (int j = 0; j < maBiblio->adherants[i].nbrLivres; j++)
      {
        if (strcmp(maBiblio->adherants[i].livres[j].titre, titre) == 0)
        {
          decalage(maBiblio->adherants[i].livres, j, maBiblio->adherants[i].nbrLivres);
          maBiblio->adherants[i].nbrLivres--;
        }
      }
    }
  }
};

// Affichage
void afficher_adherants(Biblio *maBiblio)
{
  int nbrOfAdherants = maBiblio->nbrAdherants;
  for (int i = 0; i < nbrOfAdherants; i++)
  {
    printf("==========Adherant %d==========\n", i + 1);
    printf("Numéro: %d\n", maBiblio->adherants[i].numero);
    printf("Nom: %s\n", maBiblio->adherants[i].nom);

    afficher_livres(maBiblio, i);
  }
}

void afficher_livres(Biblio *maBiblio, int i)
{
  int nbrOfLivres = maBiblio->adherants[i].nbrLivres;
  for (int j = 0; j < nbrOfLivres; j++)
  {
    printf("**Livre %d:\n", j + 1);
    printf("\tTitre: %s\n", maBiblio->adherants[i].livres[j].titre);
    printf("\tAuteur: %s\n", maBiblio->adherants[i].livres[j].auteur);
    printf("\tnombre des pages: %d\n", maBiblio->adherants[i].livres[j].nbrPage);
  }
}
