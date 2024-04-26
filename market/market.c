#include <stdio.h>
#include "market.h"

Date creation_date()
{
  Date d;
  printf("Jour: ");
  scanf("%d", &d.jour);

  printf("Mois: ");
  scanf("%d", &d.mois);

  printf("Année: ");
  scanf("%d", &d.annee);

  printf("heure: ");
  scanf("%d", &d.heure);

  printf("minute: ");
  scanf("%d", &d.min);

  return d;
}

STR_personne creation_personne()
{
  STR_personne p;

  printf("Saisir le nom complet :");
  scanf("%s", p.nom);

  printf("Saisir CIN :");
  scanf("%s", p.CIN);

  printf("Saisir le pays d'origine :");
  scanf("%s", p.pays);

  printf("Saisir la date de naissance :\n");
  p.date_nai = creation_date();

  return p;
}

STR_produit creation_produit()
{
  STR_produit p;

  printf("Saisir une désignation :");
  scanf("%s", p.designation);

  printf("Saisir prix du produit :");
  scanf("%d", &p.prix);

  return p;
}

STR_ligneCommande creation_ligneCommande()
{
  STR_ligneCommande lc;

  lc.produit = creation_produit();

  printf("Saisir quantité :");
  scanf("%d", &lc.quantite);

  return lc;
}

STR_commande creation_commande()
{
  STR_commande c;

  printf("Saisir numéro :");
  scanf("%d", &c.numero);

  c.dateTime = creation_date();

  printf("Client\n");
  c.client = creation_personne();

  printf("Saisir nombre de ligne de commande (max=10):");
  scanf("%d", &c.numOfLigneCommande);

  for (int i = 0; i < c.numOfLigneCommande; i++)
  {
    printf("======Ligne de commande %d======\n", i + 1);
    c.listeOfLigneCommande[i] = creation_ligneCommande();
  }

  printf("Saisir montant de la commande :");
  scanf("%d", &c.montant);

  return c;
}

STR_caisse creation_caisse()
{
  STR_caisse c;

  printf("Saisir numéro :");
  scanf("%d", &c.numero);

  printf("Responsable\n");
  c.responsable = creation_personne();

  printf("Saisir nombre de commande traité (max=10):");
  scanf("%d", &c.numOfCommande);

  for (int i = 0; i < c.numOfCommande; i++)
  {
    printf("======commande %d======\n", i + 1);
    c.listeOfCommande[i] = creation_commande();
  }

  return c;
}

void build_market(STR_market *m, int n)
{
  for (int i = 0; i < n; i++)
  {
    m->listeOfCaisse[i] = creation_caisse();
  }
  m->numOfCaisse = n;
}
