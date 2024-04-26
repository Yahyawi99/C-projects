// Date
typedef struct
{
  int jour;
  int mois;
  int annee;
  int heure;
  int min;
} Date;

// Personne
typedef struct
{
  char Nom[20];
  int CIN[8];
  Date date_nai;
  char pays[20];
} STR_personne;

// Produit
typedef struct
{
  char designation[20];
  float prix;
} STR_produit;

// Ligne de commande
typedef struct {
  STR_produit produit;
  int quantite;
} STR_ligneCommande;

// commande
typedef struct {
  int numero;
  Date dateTime;
  STR_personne client;
  int numOfLigneCommande;
  STR_ligneCommande listeOfLigneCommande[10];
  float montant;
}STR_commande;

// caisse
typedef struct {
  int numero;
  STR_personne responsable;
  int numOfCommande;
  STR_commande listeOfCommande[10];
}STR_caisse;


// market
typedef struct {
  int numOfCaisse;
  STR_caisse listeOfCaisse[10];
}STR_market;


// =====================================================
// ======================Functions======================
// =====================================================

