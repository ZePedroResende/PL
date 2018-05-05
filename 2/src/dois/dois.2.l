%option c++
%option noyywrap

%x dentro_categoria titulo autor

%{
#include "words.h"
TextAnalizer *ta = new TextAnalizer();
string title = "";
int i=0;
%}

STRING             [a-zA-Z]
AUTHOR             ([aA][uU][tT][hH][oO][rR])([ \n\t]+)?=([ \n\t]+)?[\{\"]
TITLE              ([tT][iI][tT][lL][eE])([ \n\t]+)?=([ \n\t]+)?[\{\"]
ALL                [.\n]

%%

\n                     ;
\@string\{             ;
\@{STRING}+\{          {yytext[yyleng-1]='\0';
                        yytext=yytext+1;
                        ta->addWord(yytext);
                        printf("BEGIN dentro_categoria --> %s\n", yytext);
                        BEGIN(dentro_categoria);}
.                       ;

<dentro_categoria>\n                     ;
<dentro_categoria>[[:alnum:]]+[ \t]*\,   {yytext[yyleng-1]='\0';cout<< "Código: "<< yytext<<endl;}
<dentro_categoria>{TITLE}                         {BEGIN (titulo);}
<dentro_categoria>{AUTHOR}                        {BEGIN (autor);}
<dentro_categoria>([ \t]*)\}([ \t]*)\n                      {cout<<"OUT!"<< endl;BEGIN 0;}
<dentro_categoria>.                  ;

<autor>\n                 putchar(' ');
<autor>(.+)/([\"\}],)     {cout << "AUTOR -->"<< yytext <<endl; BEGIN (dentro_categoria);}
<autor>.                  ;

<titulo>\n                 putchar(' ');
<titulo>(.+)/([\"\}],)     {cout << "TITULO -->"<< yytext <<endl; BEGIN 0;}
<titulo>.                  ;

%%
int main(int argc, char *argv[]) {

  FlexLexer* lexer = new yyFlexLexer;
  while(lexer->yylex() != 0);
  //ta->printer();
  return 0;
}
