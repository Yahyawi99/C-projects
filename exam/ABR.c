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

int main()
{
  arbre r = tri_Tab();

  min(r);
  max(r);

  return 0;
}