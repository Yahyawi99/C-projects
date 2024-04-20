#include <stdio.h>
#include "bank.h"

int main()
{
  STR_G grp;

  grp.nmbr_entr = 0;
  remplir_grp(&grp, 1);

  return 0;
}