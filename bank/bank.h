typedef struct
{
  int jour;
  int mois;
  int annee;
  int heure;
  int min;
} Date;

typedef struct
{
  char Nom[20];
  int CIN[8];
  Date date_nai;
  char pays[20];
} STR_P;

typedef struct
{
  char Nom[20];
  Date naissance;
  char origine[20];
  Date date_emb;
  char fonction[20];
  STR_P conjoint;
  STR_P enfants[20];
  int nmbr_enf;
} STR_EMP;

typedef struct
{
  char RS[20];
  char RC[20];
  char patente[20];
  Date date_cre;
  STR_EMP employes[20];
  int nmbr_employes;
} STR_ETR;

typedef struct
{
  STR_ETR entreprises[100];
  int nmbr_entr;
} STR_G;

void remplir_grp(STR_G *grp, int n);