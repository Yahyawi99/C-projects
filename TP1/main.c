#include <stdio.h>
#include <stdlib.h>

void exporterNote(const char *filename, float note)
{
  FILE *file = fopen(filename, "a");
  if (file == NULL)
  {
    printf("Error lors l'ouverture de fichier!\n");
    return;
  }

  fprintf(file, "%.2f\n", note);
  fclose(file);
}

void importNotes(const char *filename, int numOfNotes, float Tab[], int *length)
{
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("Error lors l'ouverture de fichier!\n");
    return;
  }

  for (int i = 0; i < numOfNotes; i++)
  {
    fscanf(file, "%f", &Tab[i]);
    (*length) = *length + 1;
  }
}

int main()
{

  const char filename[100] = "notes.txt";
  float note;
  int numOfNotes = 2;

  // export
  for (int i = 0; i < numOfNotes; i++)
  {
    printf("Saisir la note numero %d: ", i + 1);
    scanf("%f", &note);
    exporterNote(filename, note);
  }

  // import
  float T[100];
  int length = 0;
  importNotes(filename, numOfNotes, T, &length);

  printf("Les Notes importer sont : \n");
  for (int i = 0; i < length; i++)
  {
    printf("%.2f\n", T[i]);
  }

  return 0;
}