#include <stdio.h>
#include <stdlib.h>

struct cellule
{
  int emetteur;
  int recepteur;
  int montant;
  struct cellule *suiv;
};
typedef struct cellule *liste;

struct newCellule
{
  int emetteur;
  int montantGlobal;
  struct newCellule *suiv;
};
typedef struct newCellule *newListe;

newListe calculeMontantGlobal(liste L)
{
  liste p = L;
  newListe newL = NULL, nv, q;

  newL->emetteur = p->emetteur;
  newL->montantGlobal = p->montant;
  newL->suiv = NULL;
  p = p->suiv;

  while (p != NULL)
  {
    q = newL;
    while (q != NULL && (q->emetteur != p->emetteur))
      q = q->suiv;

    if (q == NULL)
    {
      nv = (newListe)malloc(sizeof(struct newCellule));
      nv->emetteur = p->emetteur;
      nv->montantGlobal = p->montant;
      nv->suiv = newL;
      newL = nv;
    }
    else
    {
      q->montantGlobal += p->montant;
    }

    p = p->suiv;
  }

  return newL;
}

int main()
{
  return 0;
}