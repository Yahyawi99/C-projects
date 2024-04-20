#include <stdio.h>
#include <string.h>
#include "bank.h"

Date cree_date()
{
  Date newDate;
  printf("\tJour: ");
  scanf("%d", &newDate.jour);

  printf("\tMois: ");
  scanf("%d", &newDate.mois);

  printf("\tAnnée: ");
  scanf("%d", &newDate.annee);

  return newDate;
}

STR_P cree_personne()
{
  STR_P newPersonne;

  printf("Saisir le nom complet :");
  scanf("%s", newPersonne.Nom);

  printf("Saisir le pays d'origine :");
  scanf("%s", newPersonne.origine);

  printf("Saisir la date de naissance :\n");
  newPersonne.date_nai = cree_date();

  return newPersonne;
}

STR_EMP cree_employe()
{
  STR_EMP newEmpl;

  STR_P personne = cree_personne();
  strcpy(newEmpl.Nom, personne.Nom);
  strcpy(newEmpl.origine, personne.origine);
  newEmpl.naissance = personne.date_nai;

  printf("Saisir la date d'embauchement :\n");
  cree_date(newEmpl.date_emb);

  printf("Saisir la fonction :");
  scanf("%s", newEmpl.fonction);

  int is_married = 0;
  printf("conjoint(e)? \n 0-Non\n 1-Oui\n->");
  scanf("%d", &is_married);

  if (is_married == 0)
  {
    return newEmpl;
  }

  newEmpl.conjoint = cree_personne();

  printf("Combien d'enfants?");
  scanf("%d", &newEmpl.nmbr_enf);

  for (int i = 0; i < newEmpl.nmbr_enf; i++)
  {
    printf("========Enfant %d========\n", i + 1);
    newEmpl.enfants[i] = cree_personne();
  }

  return newEmpl;
}

STR_ETR cree_entr()
{
  STR_ETR newEntr;

  printf("Saisir le registre social :");
  scanf("%s", newEntr.RS);

  printf("Saisir le registre de commerce :");
  scanf("%s", newEntr.RC);

  printf("Saisir la patente :");
  scanf("%s", newEntr.patente);

  printf("Saisir la date de creation :\n");
  newEntr.date_cre = cree_date();

  printf("Saisir le nombre d'employés :");
  scanf("%d", &newEntr.nmbr_employes);

  for (int i = 0; i < newEntr.nmbr_employes; i++)
  {
    printf("========Employe %d========\n", i + 1);
    newEntr.employes[i] = cree_employe();
  }

  return newEntr;
}

void remplir_grp(STR_G *grp, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("========Etnreprise %d========\n", i + 1);
    grp->entreprises[i] = cree_entr();
    grp->nmbr_entr++;
  }
}