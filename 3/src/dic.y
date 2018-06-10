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

%type<texto> MEAN SYN ENGLISH WORD
%token MEAN SYN ENGLISH WORD

%%

Dicionario: ListaPal;

ListaPal: ListaPal Palavra {install(entry,argumentos);printf("INSTALLING\n");}
        | ;

Palavra: Nome ListaArg;

Nome: WORD {argumentos = new_nome(); 
        entry = $1;
        printf("PALAVRA %s\n", entry);};

ListaArg: ListaArg Argumento
        | ;

Argumento: Mean
         | Syn
         | English;

Mean: MEAN {add_mean(&argumentos, $1); printf("MEAN %s\n", $1);};
Syn: SYN {add_sin(&argumentos, $1); printf("SYN\n");};
English: ENGLISH {add_english(&argumentos, $1); printf("ENG\n");};

%%
int main() {
  yyparse();
  printf("*******************\nIM DONE! Here are STATS:\n");
  printf("Number of words saved: %d\n", numWords());
  printf("Does 'ato' exist? %d\n", (lookup("ato")!=NULL));
  return 0;
}

void yyerror(char *erro){                                               
  fprintf(stderr, "HELP! ERROR:%s \n", erro);
}