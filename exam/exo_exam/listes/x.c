#include <stdio.h>
#include <stdlib.h>

struct cel
{
  int val;
  struct cel *preced;
  struct cel *suiv;
};
typedef struct cel *liste;

void supprimer(liste *l, int x)
{

  liste p, q;

  p = *l;

  while (p != NULL && p->val == x)
  {
    q = p;
    p = p->suiv;
    if (p != NULL)
      p->preced = NULL;
    *l = p;

    free(q);
  }

  while (p != NULL)
  {
    if (p->val == x)
    {
      q = p;
      (p->preced)->suiv = p->suiv;

      if (p->suiv != NULL)
        (p->suiv)->preced = p->preced;

      p = p->suiv;
      free(q);
    }
    else
    {
      p = p->suiv;
    }
  }
}

int main()
{
  return 0;
}