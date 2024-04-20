typedef struct
{
  char titre[100];
  char auteur[100];
  int nbrPage;
} Livre;

typedef struct
{
  char nom[20];
  int numero;
  int nbrLivres;
  Livre livres[3];
} Adherant;

typedef struct
{
  int nbrAdherants;
  Adherant adherants[20];
} Biblio;

Adherant cree_adherant();
void remplire_biblio(Biblio *maBiblio, int nbrOfNewAdherant);

void emprunter_livre(Biblio *maBiblio);

void search(Biblio *maBiblio);

void retournez(Biblio *maBiblio);

void afficher_adherants(Biblio *maBiblio);
void afficher_livres(Biblio *maBiblio, int i);