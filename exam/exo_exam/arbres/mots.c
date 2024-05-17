#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cel
{
  int num;
  struct cel *suiv;
};
typedef struct cel *numeros;

struct noeud
{
  char mot[20];
  numeros pages;
  struct noeud *fd;
  struct noeud *fg;
};
typedef struct noeud *arbre;

// ============
void insererMot(arbre *r, char motDonne[], numeros lpages)
{
  arbre N;
  if (*r == NULL)
  {
    N = (arbre)malloc(sizeof(struct noeud));
    strcpy(N->mot, motDonne);
    N->pages = lpages;
    N->fg;
    N->fd;
  }
  else if (strcmp(motDonne, N->mot) > 0)
  {
    insererMot(&(*r)->fd, motDonne, lpages);
  }
  else
  {
    insererMot(&(*r)->fg, motDonne, lpages);
  }
}

// ==========
arbre predecesseur(arbre *r)
{
  arbre p = NULL;
  if ((*r) != NULL)
  {
    if ((*r)->fd == NULL)
    {
      p = *r;
      *r = (*r)->fd;
    }
    else
    {
      p = predecesseur((*r)->fd);
    }
  }

  return p;
}

void supp(arbre *r, char motDonne[])
{
  arbre pred;
  if (*r == NULL)
  {
    return;
  }

  if (strcmp(motDonne, (*r)->mot) > 0)
  {
    supp(&(*r)->fd, motDonne);
  }
  else if (strcmp(motDonne, (*r)->mot) <= 0)
  {
    supp(&(*r)->fg, motDonne);
  }
  else
  {
    if ((*r)->fg == NULL)
    {
      *r = (*r)->fd;
    }
    else if ((*r)->fd == NULL)
    {
      *r = (*r)->fg;
    }
    else
    {
      pred = predecesseur(&(*r)->fg);
      strcpy((*r)->mot, pred->mot);
      (*r)->pages = pred->pages;
    }
  }
}

void afficher(arbre r)
{
  numeros p;
  if (r != NULL)
  {
    afficher(r->fg);

    printf("%s\n", r->mot);
    p = r->pages;
    while (p != NULL)
    {
      printf("%d,", p->num);
      p = p->suiv;
    }
    printf("\n");

    afficher(r->fd);
  }
}

int main()
{
  return 0;
}