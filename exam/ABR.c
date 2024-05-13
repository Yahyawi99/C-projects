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
    printf("valeur inexistante\n");
    return 0;
  }

  if (A->num == n)
  {
    printf("valeur existe\n");
    return 1;
  }

  if (n > A->num)
    return nodeSearch(A->fd, n);

  if (n < A->num)
    return nodeSearch(A->fg, n);
}

// Insertion
void insertion(arbre *A, int n)
{
  arbre N;
  if (*A == NULL)
  {
    N = (arbre)malloc(sizeof(struct noeud));
    N->fg = NULL;
    N->num = n;
    N->fd = NULL;
    *A = N;
  }
  else if (n > (*A)->num)
  {
    insertion(&(*A)->fd, n);
  }
  else
  {
    insertion(&(*A)->fg, n);
  }
}

// Tri
arbre tri_Tab()
{
  arbre N = NULL;
  int n, val;
  printf("Saisir la taille de tableau : ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    printf("Saisir une valeur : ");
    scanf("%d", &val);

    insertion(&N, val);
  }

  return N;
}

void infixe(arbre A)
{
  if (A != NULL)
  {
    infixe(A->fg);
    printf("%d, ", A->num);
    infixe(A->fd);
  }
}

// minimum & maximum
void min(arbre A)
{
  if (A == NULL)
  {
    printf("Valeur n'existe pas");
    return;
  }

  if (A->fg == NULL)
  {
    printf("Valeur minimum est %d.\n", A->num);
    return;
  }
  else
  {
    min(A->fg);
  }
}

void max(arbre A)
{
  if (A == NULL)
  {
    printf("Valeur n'existe pas");
    return;
  }

  if (A->fd == NULL)
  {
    printf("Valeur maximum est %d.\n", A->num);
    return;
  }
  else
  {
    max(A->fd);
  }
}

// Supprimer
arbre predecesseur(arbre *r)
{
  arbre p = NULL;
  if (*r != NULL)
  {
    if ((*r)->fd == NULL)
    {
      p = *r;
      *r = (*r)->fg;
    }
    else
    {
      p = predecesseur(&(*r)->fd);
    }
  }

  return p;
}

arbre successeur(arbre *r)
{
  arbre p = NULL;
  if (*r != NULL)
  {
    if ((*r)->fg == NULL)
    {
      p = *r;
      *r = (*r)->fd;
    }
    else
    {
      p = successeur(&(*r)->fg);
    }
  }

  return p;
}

void enlever(arbre *r, int x)
{
  arbre res = NULL;
  if (*r != NULL)
  {
    if (x > (*r)->num)
    {
      enlever(&(*r)->fd, x);
    }
    else if (x < (*r)->num)
    {
      enlever(&(*r)->fg, x);
    }
    else
    {
      if ((*r)->fg == NULL)
      {
        (*r) = (*r)->fd;
      }
      else if ((*r)->fd == NULL)
      {
        (*r) = (*r)->fg;
      }
      else
      {
        res = successeur(&(*r)->fd);
        (*r)->num = res->num;
      }
    }
  }
}

int main()
{
  arbre r = tri_Tab();

  infixe(r);

  printf("\n");

  enlever(&r, 8);

  infixe(r);

  printf("\n");

  return 0;
}