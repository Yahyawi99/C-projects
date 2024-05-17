#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noeud
{
  char Nom[10];
  struct noeud *PF;
  struct noeud *FR;
};
typedef struct noeud *arbre;

// ==========
arbre chercher(arbre r, char NomDonne[])
{
  arbre p = NULL;
  if (r == NULL || strcmp(r->Nom, NomDonne) == 0)
  {
    return r;
  }
  else
  {
    p = chercher(r->PF, NomDonne);

    if (p != NULL)
      return p;
    else
      return chercher(r->FR, NomDonne);
  }
}

// =======
int enfant(arbre Y, char X[])
{

  arbre p = Y->PF;

  while (p != NULL && strcmp(X, p->Nom) != 0)
    p = p->FR;

  if (p == NULL)
    return 0;
  else
    return 1;
}

// ======
void naissance(arbre r, char NomPere[], char NomBebe[])
{
  arbre p, q, r, copy;

  p = chercher(r, NomPere);

  if (p != NULL)
  {
    q = (arbre)malloc(sizeof(struct noeud));
    strcpy(p->Nom, NomBebe);
    q->PF = NULL;
    q->FR = NULL;

    if (p->PF == NULL)
    {
      p->PF = q;
    }
    else
    {
      r = p->FR;
      while (r != NULL)
      {
        copy = r;
        r = r->FR;
      }

      copy->FR = q;
    }
  }
}

int main()
{
  return 0;
}