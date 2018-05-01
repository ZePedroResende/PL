#include "linkedhash.h"
#include <stdio.h>


int main(int argc, char *argv[]){
  char *name = "coisa";
  install(name);
  install(name);

  Nlist np;
  np = lookup(name);
  if(np != NULL)
    printf("%d vezes", np->count);

  return 0 ;
}
