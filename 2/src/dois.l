%option c++
%option noyywrap

%x dentro_categoria
%x next_autor

%{
#include "words.h"
WordCounter *wc = new WordCounter();
int i=0;
%}

STRING             [a-zA-Z]
AUTHOR             ([aA][uU][tT][hH][oO][rR])
TITLE              ([tT][iI][tT][lL][eE])

%%

\n                     ;
\@{STRING}+\{           {yytext[yyleng-1]='\0';yytext=yytext+1;wc->addWord(yytext);printf("BEGIN dentro_categoria\n %s\n", yytext);BEGIN(dentro_categoria);}
.                       ;

<dentro_categoria>[[:alnum:]]+,   {printf("Código: %s", yytext); BEGIN next_autor;}
<dentro_categoria>.               ;
<dentro_categoria>\}              {BEGIN 0;}

%%
int main(int argc, char *argv[]) {

  FlexLexer* lexer = new yyFlexLexer;
  while(lexer->yylex() != 0);
  wc->printer(2);
  return 0;
}
