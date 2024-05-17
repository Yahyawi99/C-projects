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
    dernier->suiv = P;
    return S;
  }

  if (Q != NULL)
  {

    dernier->suiv = Q;
    return S;
  }

  return S;
}

int main()
{

  Polynomme P, x, y, Q, z, S;

  P = (Polynomme)malloc(sizeof(struct poly));
  P->coeff = 2;
  P->suiv = NULL;

  x = (Polynomme)malloc(sizeof(struct poly));
  x->coeff = 1;
  x->suiv = NULL;
  P->suiv = x;

  y = (Polynomme)malloc(sizeof(struct poly));
  y->coeff = 3;
  y->suiv = NULL;
  x->suiv = y;

  //************

  Q = (Polynomme)malloc(sizeof(struct poly));
  Q->coeff = 1;
  Q->suiv = NULL;

  z = (Polynomme)malloc(sizeof(struct poly));
  z->coeff = 5;
  z->suiv = NULL;
  Q->suiv = z;

  S = NULL;
  S = somme(P, Q);

  while (S != NULL)
  {
    printf("%d,", S->coeff);
    S = S->suiv;
  }

  printf("\n");

  return 0;
}