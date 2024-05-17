#include <stdio.h>
#include <stdlib.h>

struct cel
{
  int val;
  struct cel *suiv;
};
typedef struct cel *liste;

liste concat(liste a, liste b)
{
  liste last, c = a;

  while (c != NULL)
  {
    last = c;
    c = c->suiv;
  }

  last->suiv = b;

  return c;
}

int main()
{
  return 0;
}