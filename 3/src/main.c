#include"linkedhash.h"
#include<assert.h>
int main(){
  nome n = (new_nome());
  nome n2 = (new_nome());

  char *palavra= "depois";
  char *mean = "tarde";
  char *sin1= "atrasado";
  char *sin2= "lol";
  char *english= "late";

  add_mean(&n,mean);
  add_sin(&n,sin1);
  add_sin(&n,sin2);
  add_english(&n,english);

  char *palavra1= "zoloo";
  char *mean1 = "tarde1";
  char *sin11= "atrasado1";
  char *sin21= "lol1";
  char *english1= "late1";

  add_mean(&n2,mean1);
  add_sin(&n2,sin11);
  add_sin(&n2,sin21);
  add_english(&n2,english1);

  install(palavra,n);
  install(palavra1,n2);

nome a =  lookup_nome(palavra);
nome a1 =  lookup_nome(palavra1);
assert(a != NULL);

  printf("%s \n",a->mean);
  printf("%d \n",a->counter);
  printf("%s \n",a->english);
sin *s = &(a->sinonimos);
  while((*s) != NULL){
    printf("%s\n", (*s)->name);
    s = &(*s)->next;
  }

  printf("sdaasdsa\n");

  nlist lol = get_used_list();
  nlist *l = &lol;
  while((*l) != NULL){
    printf("%s\n", (*l)->name);
    l = &(*l)->next;
  }
  printf("sdaasdsa\n");

  print_footnote();

  return 0;
}
