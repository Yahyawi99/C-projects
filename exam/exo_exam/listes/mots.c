#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct celpage
{
  int num;
  struct celpage *suiv;
};
typedef struct cel *lpages;

struct celmot
{
  char mot[100];
  lpages pages;
  struct celmot *suiv;
};
typedef struct celmot *liste;

void ajouter(liste *l, char MOTDONNE[], lpages LPAGE)
{

  liste p = *l, nv, dernier = NULL;

  while (p != NULL && strcmp(p->mot, MOTDONNE) < 0)
  {
    dernier = p;
    p = p->suiv;
  }

  nv = (liste)malloc(sizeof(struct celmot));
  nv->suiv = dernier->suiv;
  strcpy(nv->mot, MOTDONNE);
  nv->pages = LPAGE;
  dernier->suiv = nv;
}

int main()
{

  return 0;
}