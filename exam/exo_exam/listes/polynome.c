#include <stdio.h>
#include <stdlib.h>

struct poly
{
  int coeff;
  struct poly *suiv;
};
typedef struct poly *Polynomme;

Polynomme somme(Polynomme P, Polynomme Q)
{
  Polynomme S, nv, dernier = NULL;

  while (P != NULL && Q != NULL)
  {
    if (P->coeff + Q->coeff != 0)
    {
      if (S == NULL)
      {
        S = (Polynomme)malloc(sizeof(struct poly));
        S->coeff = P->coeff + Q->coeff;
        S->suiv = NULL;
        dernier = S;
      }
      else
      {
        nv = (Polynomme)malloc(sizeof(struct poly));
        nv->coeff = P->coeff + Q->coeff;
        nv->suiv = NULL;
        dernier = nv;
      }
    }

    P = P->suiv;
    Q = Q->suiv;
  }

  if (P != NULL)
  {
    while (P != NULL)
    {
      nv = (Polynomme)malloc(sizeof(struct poly));
      nv->coeff = P->coeff;
      nv->suiv = NULL;
      dernier = nv;

      P = P->suiv;
    }
  }

  if (Q != NULL)
  {
    while (Q != NULL)
    {
      nv = (Polynomme)malloc(sizeof(struct poly));
      nv->coeff = P->coeff;
      nv->suiv = NULL;
      dernier = nv;

      Q = Q->suiv;
    }
  }

  return S;
}

int main()
{
  return 0;
}