typedef struct
{
  char nom[20];
  char prenom[20];
  float notes[3];
  float moyenne;
} Etudiant;

void remplissage(Etudiant *liste, int N);

void affichage(Etudiant *liste, int N);

Etudiant search(Etudiant *liste, int N);