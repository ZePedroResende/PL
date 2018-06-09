%option noyywrap
%{
#include"linkedhash.h"
%}

SPACE ([ \n\t]+)
NOME ([a-zA-Z]|[áàâãéèêíóôúçñÁÀÂÃÉÈÍÓÔÕÚÇ]|[0-9])

%%
{SPACE}   {}
{NOME}+   { lookup_nome(yytext);}
.         {}
%%
