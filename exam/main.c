#include <stdio.h>
#include <stdlib.h>

struct noeud
{
  struct noeud *fg;
  int num;
  struct noeud *fd;
};
typedef struct noeud *arbre;

// creation
arbre creation(int n)
{
  arbre N;
  N = (arbre)malloc(sizeof(struct noeud));
  if (N == NULL)
  {
    printf("Error d'allocation!!\n");
    exit(1);
  }

  N->fg = NULL;
  N->num = n;
  N->fd = NULL;

  return N;
}

// nombre de noeud
int numOfNodes(arbre A)
{

  if (A == NULL)
  {
    return 0;
  }

  return 1 + numOfNodes(A->fg) + numOfNodes(A->fd);
}

// nombre des feuilles
int numOfLeafs(arbre A)
{
  if (A == NULL)
  {
    return 0;
  }

  if (A->fg == NULL && A->fd == NULL)
  {
    return 1;
  }

  return numOfLeafs(A->fg) + numOfLeafs(A->fd);
}

// Hauteur d'un arbre
int max(int a, int b)
{
  return a > b ? a : b;
}

int hauteur(arbre A)
{

  if (A == NULL || (A->fg == NULL && A->fd == NULL))
  {
    return 0;
  }

  return 1 + max(hauteur(A->fg), hauteur(A->fd));
}

int main()
{
  return 0;
}