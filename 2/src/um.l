%option c++
%option noyywrap
%{
#include "words.h"
WordCounter *wc = new WordCounter();
%}

STRING             [a-zA-Z]

%%

[ \n\t]                 ;
\@{STRING}+\{           {yytext[yyleng-1]='\0';yytext=yytext+1;wc->addWord(yytext);}
.                       ;

%%
int main(int argc, char *argv[]) {

  FlexLexer* lexer = new yyFlexLexer;
  while(lexer->yylex() != 0);
  wc->printer(1);
  return 0;
}
