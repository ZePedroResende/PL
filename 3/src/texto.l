%option noyywrap
%{
#include"linkedhash.h"
%}

SPACE ([ \n\t]+)
NOME ([a-zA-Z]|[áàâãéèêíóôúçñÁÀÂÃÉÈÍÓÔÕÚÇ]|[0-9])

%%
{NOME}+   { nome n = lookup_nome(yytext);
            if(n){
              printf("%s <a href=\"#section%d\">[%d]</a>",yytext,n->indice,n->indice);
            }
            else{
              printf("%s",yytext);
            }
          }
%%

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
  yylex();
  print_footnote();
  return 0;
}
