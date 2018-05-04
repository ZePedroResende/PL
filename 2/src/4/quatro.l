%option c++
%option noyywrap
%x AUTHOR
%{
#include "Graph.h"
Graph* g = new Graph();
vector<string> names;
string  name ("\"");
ofstream ofs;
%}

autor author([ \n\t]+)?=([ \n\t]+)?
LOL [a-zA-ZáàâãéèêíóôúçñÁÀÂÃÉÈÍÓÔÕÚÇ]
NOME ([a-zA-Z]|á|à|â|ã|é|è|ê|í|ó|ô|ú|ç|ñ|Á|À|Â|Ã|É|È|Í|Ó|Ô|Õ|Ú|Ç)

%%
[ \n\t]                                                ;
<*>{autor}                                             BEGIN AUTHOR;
<AUTHOR>[{"]                                           ;
<AUTHOR>([ \n\t]+)and([ \n\t]*)(and)?                      { name.append("\""); names.push_back(name); name.clear(); name.append("\"");}
<AUTHOR>\.                                             { name.append("\\"); name.append(yytext); }
<AUTHOR>[\n\t]                                         ;
<AUTHOR>{NOME}                                         { name.append(yytext);}
<AUTHOR>([ \n\t]*)?[}"]([ \n\t]*)?,                    { name.append("\""); names.push_back(name); name.clear(); name.append("\"");g->addColaborator(names); names.clear();BEGIN INITIAL;}
<AUTHOR>.                                              ;
.                                                      ;
%%
int main(int argc, char *argv[]) {
  FlexLexer* lexer = new yyFlexLexer;
  if (argc == 1){
    while(lexer->yylex() != 0);
  }
  if (argc == 2){
    yyin = fopen(argv[2], "r");
    while(lexer->yylex() != 0);
    g->printRede();
  }

  if (argc == 3){
    yyin = fopen(argv[2], "r");
    while(lexer->yylex() != 0);
    g->printRede();
  }
  return 0;
}
