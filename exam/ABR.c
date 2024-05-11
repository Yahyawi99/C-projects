#include <stdio.h>
#include <stdlib.h>

struct noeud
{
  struct noeud *fg;
  int num;
  struct noeud *fd;
};
typedef struct noeud *arbre;

// Recherche
int nodeSearch(arbre A, int n)
{
  if (A == NULL)
  {
    return 0;
  }
}

int main()
{
  return 0;
}