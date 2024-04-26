#include <stdio.h>
#include "market.h"

// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// Creation
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================

Date creation_date()
{
  Date d;
  printf("Jour: ");
  scanf("%d", &d.jour);

  printf("Mois: ");
  scanf("%d", &d.mois);

  printf("Année: ");
  scanf("%d", &d.annee);

  return d;
}

Date creation_dateTime()
{
  DateTime d;
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

  printf("Saisir le nom complet: ");
  scanf("%s", p.nom);

  printf("Saisir CIN: ");
  scanf("%s", p.CIN);

  printf("Saisir le pays d'origine: ");
  scanf("%s", p.pays);

  printf("**Saisir la date de naissance :\n");
  p.date_nai = creation_date();

  return p;
}

STR_produit creation_produit()
{
  STR_produit p;

  printf("Saisir une désignation: ");
  scanf("%s", p.designation);

  printf("Saisir prix du produit: ");
  scanf("%f", &p.prix);

  return p;
}

STR_ligneCommande creation_ligneCommande()
{
  STR_ligneCommande lc;

  lc.produit = creation_produit();

  printf("Saisir quantité: ");
  scanf("%d", &lc.quantite);

  return lc;
}

STR_commande creation_commande()
{
  STR_commande c;

  printf("Saisir numéro: ");
  scanf("%d", &c.numero);

  printf("**Date et heure:\n");
  c.dateTime = creation_dateTime();

  printf("**Client:\n");
  c.client = creation_personne();

  printf("Saisir nombre de ligne de commande (max=10): ");
  scanf("%d", &c.numOfLigneCommande);

  for (int i = 0; i < c.numOfLigneCommande; i++)
  {
    printf("======Ligne de commande %d======\n", i + 1);
    c.listeOfLigneCommande[i] = creation_ligneCommande();
  }

  printf("Saisir montant de la commande: ");
  scanf("%f", &c.montant);

  return c;
}

STR_caisse creation_caisse()
{
  STR_caisse c;

  printf("Saisir numéro: ");
  scanf("%d", &c.numero);

  printf("**Responsable:\n");
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
  printf("**************************************************\n");
  printf("Creation\n");
  printf("**************************************************\n");

  for (int i = 0; i < n; i++)
  {
    m->listeOfCaisse[i] = creation_caisse();
  }
  m->numOfCaisse = n;
}

// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// Affichage
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================
// =============================================

void afficher_date(Date d)
{
  printf("%d/%d/%d\n", d.jour, d.mois, d.annee);
}

void afficher_dateTime(DateTime d)
{
  printf("%d/%d/%d-%d:%d\n", d.jour, d.mois, d.annee, d.heure, d.min);
}

void afficher_personne(STR_personne p)
{
  printf("Nom complet: %s\n", p.nom);

  printf("CIN: %s\n", p.CIN);

  printf("Le pays d'origine: %s\n", p.pays);

  printf("**Date:\n");
  afficher_date(p.date_nai);
}

void afficher_produit(STR_produit p)
{
  printf("Désignation: %s", p.designation);
  printf("Prix: %.2f", p.prix);
}

void afficher_ligneCommande(STR_ligneCommande lc)
{
  afficher_produit(lc.produit);

  printf("Quantité: %d", lc.quantite);
}

void afficher_commande(STR_commande c)
{

  printf("numéro: %d", c.numero);

  printf("**Date et heure:\n");
  afficher_dateTime(c.dateTime);

  printf("**Client:\n");
  afficher_personne(c.client);

  for (int i = 0; i < c.numOfLigneCommande; i++)
  {
    printf("======Ligne de commande %d======\n", i + 1);
    afficher_ligneCommande(c.listeOfLigneCommande[i]);
  }
}

void afficher_caisse(STR_caisse c)
{
  printf("numéro: %d\n", c.numero);

  printf("**Responsable:\n");

  afficher_personne(c.responsable);

  for (int i = 0; i < c.numOfCommande; i++)
  {
    printf("======commande %d======\n", i + 1);
    afficher_commande(c.listeOfCommande[i]);
  }
}

void affichage(STR_market m)
{
  printf("**************************************************\n");
  printf("Affichage\n");
  printf("**************************************************\n");
  for (int i = 0; i < m.numOfCaisse; i++)
  {
    afficher_caisse(m.listeOfCaisse[i]);
  }
}