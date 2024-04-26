#include <stdio.h>
#include "market.h"

Date creation_date()
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