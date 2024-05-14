#include <stdio.h>
#include <stdlib.h>

struct noeud
{
  struct noeud *fg;
  int val;
  struct noeud *fd;
};
typedef struct noeud *arbre;

void ajoute(arbre r, int a, int x)
{
  if (r != NULL)
  {
    if (r->val > x)
    {
      r->val += a;
    }

    ajoute(r->fd, a, x);
    ajoute(r->fg, a, x);
  }
}

int main()
{
  return 0;
}