#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spectacle.h"

Date create_Date()
{
  Date d;

  printf("Saisir jour : \n");
  scanf("%d", d.jj);
  printf("Saisir moi : \n");
  scanf("%d", d.mm);
  printf("Saisir anne : \n");
  scanf("%d", d.yyyy);

  return d;
}

Person create_person()
{
  Person p;

  printf("Saisir nom : \n");
  scanf("%s", p.nom);
  printf("Saisir pays d'origine : \n");
  scanf("%s", p.origin);
  p.naissance = create_Date();

  return p;
}

Time create_duree()
{
  Time t;

  printf("Saisir heure : \n");
  scanf("%d", t.heure);
  printf("Saisir minutes : \n");
  scanf("%d", t.min);

  return t;
}

Spectacle create_spectacle()
{
  Spectacle sp;

  printf("Saisir titre : \n");
  scanf("%s", sp.titre);
  printf("Saisir theme : \n");
  scanf("%s", sp.theme);
  printf("Saisir annee de sortie : \n");
  scanf("%d", sp.anneSortie);

  sp.realisateur = create_person();

  sp.duree = create_duree();
}

void saisirSpectacle(CD_THEQUE *CD, int n)
{
  for (int i = 0; i < n; i++)
  {
    CD->listeOfSpectale[i] = create_spectacle();
  }

  CD->numOfSpectacle = n;
}

/***********************/
int search_by_theme(Spectacle liste[], int n, char theme[])
{
  for (int i = 0; i < n; i++)
  {
    if (strcmp(liste[1].theme, theme) == 0)
    {
      return i;
    }
  }

  return -1;
}

int search_by_titre(Spectacle liste[], int n, char titre[])
{
  for (int i = 0; i < n; i++)
  {
    if (strcmp(liste[1].titre, titre) == 0)
    {
      return i;
    }
  }

  return -1;
}

void saisirActeurs(CD_THEQUE *CD, char theme[])
{
  int index = search_by_theme(CD->listeOfSpectale, CD->numOfSpectacle, theme);

  if (index == -1)
  {
    printf("Spectacle n'existe pas!\n");
    return;
  }

  printf("Saisir nombre d'acteur : \n");
  scanf("%d", &CD->listeOfSpectale[index].numOfActeur);

  for (int i = 0; i < CD->listeOfSpectale[index].numOfActeur; i++)
  {
    CD->listeOfSpectale[index].listeActeur[i] = create_person();
  }
}

/***************************/
void afficher_time(Time t)
{
  printf("Duree de spectacle : \n");
  printf("heure : %d\n", t.heure);
  printf("minutes : %d\n", t.min);
}

void afficher_date(Date d)
{
  printf("Date de naissance : ");
  printf("Jour : %d\n", d.jj);
  printf("Moi : %d\n", d.mm);
  printf("Annee : %d\n", d.yyyy);
}

void afficher_person(Person p)
{

  printf("Nom : %s\n", p.nom);
  printf("Pays d'origine : %s\n", p.origin);
  afficher_date(p.naissance);
}

void afficher_acteur(Person liste[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("**Acteur 1\n");
    afficher_person(liste[i]);
  }
}

void afficher_spectacle(Spectacle sp)
{
  printf("Titre : %s\n", sp.titre);
  printf("Theme : %s\n", sp.theme);
  printf("Annee de sortie : %d\n", sp.anneSortie);
  afficher_time(sp.duree);

  afficher_person(sp.realisateur);

  afficher_acteur(sp.listeActeur, sp.numOfActeur);
}

void afficher_Spectacle_by_theme(CD_THEQUE CD, char theme[])
{

  int index = search_by_theme(CD.listeOfSpectale, CD.numOfSpectacle, theme);

  if (index == -1)
  {
    printf("Spectacle n'existe pas!\n");
    return;
  }

  afficher_spectacle(CD.listeOfSpectale[index]);
};

// ******************
void afficher_Spectacle_by_titre(CD_THEQUE CD, char titre[])
{
  int index = search_by_titre(CD.listeOfSpectale, CD.numOfSpectacle, titre);

  if (index == -1)
  {
    printf("Spectacle n'existe pas!\n");
    return;
  }

  afficher_spectacle(CD.listeOfSpectale[index]);
}

// **********************
void afficher_acteurs(CD_THEQUE CD, char titre[])
{
  int index = search_by_titre(CD.listeOfSpectale, CD.numOfSpectacle, titre);

  if (index == -1)
  {
    printf("Spectacle n'existe pas!\n");
    return;
  }

  afficher_acteur(CD.listeOfSpectale[index].listeActeur, CD.listeOfSpectale[index].numOfActeur);
}

// **********************
int acteur_existe(Spectacle sp, char nomActeur[])
{
  for (int i = 0; i < sp.numOfActeur; i++)
  {
    if (strcmp(sp.listeActeur[i].nom, nomActeur) == 0)
    {
      return 1;
    }
  }

  return 0;
}

void afficher_Spectacle_by_acteur(CD_THEQUE CD, char nomActeur[])
{
  for (int i = 0; i < CD.numOfSpectacle; i++)
  {

    int res = acteur_existe(CD.listeOfSpectale[i], nomActeur);

    if (res == 1)
    {
      printf("Titre : %s\n", CD.listeOfSpectale[i].titre);
      afficher_person(CD.listeOfSpectale[i].realisateur);
    }
  }
}

/*********************/
void supprimer_spectacle(CD_THEQUE *CD, char titre[])
{
  int index = search_by_titre(CD->listeOfSpectale, CD->numOfSpectacle, titre);

  if (index == -1)
  {
    printf("Spectacle n'existe pas!\n");
    return;
  }

  for (int i = index; i < CD->numOfSpectacle - 1; i++)
  {
    CD->listeOfSpectale[i] = CD->listeOfSpectale[i + 1];
  }

  CD->numOfSpectacle--;
};

/********************/
void modifier_spectacle(CD_THEQUE CD, char titre[])
{
  int index = search_by_titre(CD.listeOfSpectale, CD.numOfSpectacle, titre);

  if (index == -1)
  {
    printf("Spectacle n'existe pas!\n");
    return;
  }

  for (int i = 0; i < CD.listeOfSpectale->numOfActeur; i++)
  {
    printf("**Acteur 1\n");
    CD.listeOfSpectale->listeActeur[i] = create_person();
  }
}

// *************************************
// *************************************
// *************************************
// *************************************
// *************************************
// *************************************
// *************************************
// *************************************
void exporter(char filename[], CD_THEQUE CD)
{
  FILE *f = fopen(filename, "w");

  if (f == NULL)
  {
    printf("Error d'exporter!");
    return;
  }

  for (int i = 0; i < CD.numOfSpectacle; i++)
  {
    Spectacle sp = CD.listeOfSpectale[i];
    fprintf(f, "%s %s %d %d %d %d\n", sp.titre, sp.theme, sp.anneSortie, sp.duree.heure, sp.duree.min, sp.numOfActeur);

    fprintf(f, "%s %s %d %d %d\n", sp.realisateur.nom, sp.realisateur.origin, sp.realisateur.naissance.jj, sp.realisateur.naissance.mm, sp.realisateur.naissance.yyyy);

    for (int j = 0; j < sp.numOfActeur; j++)
    {
      fprintf(f, "%s %s %d %d %d\n", sp.listeActeur[j].nom, sp.listeActeur[j].origin, sp.listeActeur[j].naissance.jj, sp.listeActeur[j].naissance.mm, sp.listeActeur[j].naissance.yyyy);
    }
  }

  fclose(f);
}

// ****
void importer(char filename[], CD_THEQUE *CD)
{
  int i = 0;
  FILE *f = fopen(filename, "r");

  if (f == NULL)
  {
    printf("Error d'importer!");
    return;
  }

  while (!feof(f))
  {
    fscanf(f, "%s %s %d %d %d %d\n", CD->listeOfSpectale[i].titre, CD->listeOfSpectale[i].theme, &CD->listeOfSpectale[i].anneSortie, &CD->listeOfSpectale[i].duree.heure, &CD->listeOfSpectale[i].duree.min, &CD->listeOfSpectale[i].numOfActeur);

    fscanf(f, "%s %s %d %d %d\n", CD->listeOfSpectale[i].realisateur.nom, CD->listeOfSpectale[i].realisateur.origin, &CD->listeOfSpectale[i].realisateur.naissance.jj, &CD->listeOfSpectale[i].realisateur.naissance.mm, &CD->listeOfSpectale[i].realisateur.naissance.yyyy);

    for (int j = 0; j < CD->listeOfSpectale[i].numOfActeur; j++)
    {
      fscanf(f, "%s %s %d %d %d\n", CD->listeOfSpectale[i].listeActeur[j].nom, CD->listeOfSpectale[i].listeActeur[j].origin, &CD->listeOfSpectale[i].listeActeur[j].naissance.jj, &CD->listeOfSpectale[i].listeActeur[j].naissance.mm, &CD->listeOfSpectale[i].listeActeur[j].naissance.yyyy);
    }

    i++;
    CD->numOfSpectacle = i;

    fclose(f);
  }
}
