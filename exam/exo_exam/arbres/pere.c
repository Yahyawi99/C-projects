#include <stdio.h>
#include <stdlib.h>

struct noeud
{
  int num;
  struct noeud *fg;
  struct noeud *fd;
};

typedef struct noeud *arbre;

// le parametre pere est NULL par defaut car le racine est n'a pas un pere0
arbre PERE(arbre r, int x, arbre pere)
{
  if (r != NULL)
  {
    if (x == r->num)
    {
      return pere;
    }
    else if (x > r->num)
    {
      return PERE(r->fd, x, r);
    }
    else
    {
      return PERE(r->fg, x, r);
    }
  }
}
