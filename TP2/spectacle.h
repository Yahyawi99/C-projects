typedef struct
{
  int jj;
  int mm;
  int yyyy;
} Date;

typedef struct
{
  int min;
  int heure;
} Time;

typedef struct
{
  char nom[20];
  char origin[20];
  Date naissance;
} Person;

typedef struct
{
  char titre[20];
  char theme[20];
  int anneSortie;
  int numOfActeur;
  Time duree;
  Person realisateur;
  Person listeActeur[100];
} Spectacle;

typedef struct
{
  Spectacle listeOfSpectale[100];
  int numOfSpectacle;
} CD_THEQUE;

// 3
void saisirSpectacle(CD_THEQUE *CD, int n);

// 4
void saisirActeurs(CD_THEQUE *CD, char theme[]);

// 5
void afficher_Spectacle_by_theme(CD_THEQUE CD, char theme[]);

// 6
void afficher_acteurs(CD_THEQUE CD, char titre[]);

// 7
void afficher_Spectacle_by_acteur(CD_THEQUE CD, char nomActeur[]);

// 8
void supprimer_spectacle(CD_THEQUE *CD, char titre[]);

// 9
void modifier_spectacle(CD_THEQUE CD, char titre[]);

// bonus
void exporter(char filename[], CD_THEQUE CD);