%option c++
%option noyywrap
%x AUTHOR
%{
#include "Graph.h"
Graph* g = new Graph();
vector<string> names;
string  name;
%}

autor author([ \n\t]+)?=([ \n\t]+)?
NOME [a-zA-ZáàâãéèêíóôúçñÁÀÂÃÉÈÍÓÔÕÚÇ ]

%%
[ \n\t]                       ;
<*>{autor}  BEGIN AUTHOR;
<AUTHOR>[{"]                    ;
<AUTHOR>[ \n\t]+and[ \n\t]+                       { names.push_back(name); name.clear();}
<AUTHOR>{NOME} { name.append(yytext);}
<AUTHOR>([ \n\t]*)?[}"]([ \n\t]*)?,                    {names.push_back(name); name.clear();g->addColaborator(names); names.clear();BEGIN INITIAL;}
<AUTHOR>[ \n\t]                       ;
<AUTHOR>.                       ;

.                             ;
%%
int main(int argc, char *argv[]) {

  FlexLexer* lexer = new yyFlexLexer;
  while(lexer->yylex() != 0);
  g->printRede();
  return 0;
}
