%option noyywrap
%{
#include"linkedhash.h"
#include"html.h"
FILE *out;
%}

SPACE ([ \n\t]+)
NOME ([a-zA-Z]|[áàâãéèêíóôúçñÁÀÂÃÉÈÍÓÔÕÚÇ]|[0-9])

%%
^{NOME}+  {
            fprintf(out,"<p>");
            nome n = lookup_nome(yytext);
            if(n){
              fprintf(out,"<b>%s</b> <a href=\"#section%d\">[%d]</a>",yytext,n->indice,n->indice);
            }
            else{
              fprintf(out,"%s",yytext);
            }
          }
^[ \t]+  {fprintf(out,"<p>%s",yytext);}


{NOME}+$ {
            nome n = lookup_nome(yytext);
            if(n){
              fprintf(out,"<b>%s</b> <a href=\"#section%d\">[%d]</a>",yytext,n->indice,n->indice);
            }
            else{
              fprintf(out,"%s",yytext);
            }
            fprintf(out,"</p>");
          }
\n {fprintf(out,"</p>%s",yytext);}
{NOME}+   { nome n = lookup_nome(yytext);
            if(n){
              fprintf(out,"<b>%s</b> <a href=\"#section%d\">[%d]</a>",yytext,n->indice,n->indice);
            }
            else{
              fprintf(out,"%s",yytext);
            }
          }
(.|[ \t]) {fprintf(out,"%s",yytext);}
%%

void lex(int argc, char* argv[]){

  char *apend = "apendice.html";
  if(argc == 1) {
      out = stdout;
      yylex();
      print_footnote(out);
      out = fopen(apend, "w");
      print_used_list(out);

  }
  else {
      for(int i = 1; i < argc; i++) {
          char s[500];
          sprintf(s, "%s.html", argv[i]);
          out = fopen(s, "w");
          yyin = fopen(argv[i], "r");
          htmlStart(out);
          yylex();
          print_footnote(out);
          reset_indice();
          fclose(out);
      }
        out = fopen(apend, "w");
        print_used_list(out);
  }
}
