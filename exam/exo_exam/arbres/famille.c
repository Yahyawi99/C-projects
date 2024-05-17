#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noeud
{
  char Nom[10];
  struct noeud *PF;
  struct noeud *FR;
};
typedef struct noeud *famille;

// ==========
famille chercher(famille r, char NomDonne)
{
  famille p = NULL;
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
      chercher(r->FR, NomDonne);
  }
}

int main()
{
  return 0;
}