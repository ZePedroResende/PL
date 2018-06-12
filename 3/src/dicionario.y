%{
#include"linkedhash.h"

extern int yylex();
extern int yylineno;
extern char *yytext;
void yyerror(char*);

char* entry;
nome argumentos; 
%}
%union{
  char* texto;
}

%type<texto> WORD MEAN SYN ENGLISH 
%token MEAN SYN ENGLISH WORD

%%

Dicionario: ListaPal
          ;

ListaPal: ListaPal Palavra {install(entry,argumentos);}
        | ;

Palavra: Nome ListaArg
       ;

Nome: WORD {argumentos = new_nome(); entry = $1;};

ListaArg: ListaArg Argumento
        | ;

Argumento: MEAN {add_mean(&argumentos, $1);}
         | SYN {add_sin(&argumentos, $1);}
         | ENGLISH {add_english(&argumentos, $1);};

%%
int main() {
  yyparse();
  printf("*******************\nIM DONE! Here are STATS:\n");
  printf("Number of words saved: %d\n", numWords());
  return 0;
}

void yyerror(char *erro){                                               
  fprintf(stderr, "HELP! ERROR:%s \n", erro);
}
