%option c++
%option noyywrap

%x dentro_categoria processa_autor processa_titulo

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

<dentro_categoria>{AUTHOR}            {BEGIN (processa_autor);cout << "BEGIN AUTOR!" << endl;}
<dentro_categoria>[[:alnum:]]+[ \t]*\,   {yytext[yyleng-1]='\0';printf("Código: %s", yytext);}
<dentro_categoria>[ \t]*\}          {cout<<"OUT"<<endl;BEGIN 0;}
<dentro_categoria>.                 ;


<processa_autor>(.+)/([\"\}],)     {cout<<"AUTOR -->"<<yytext<<endl;}
<processa_autor>{TITLE}            {BEGIN (processa_titulo);cout << "BEGIN TITULO!" << endl<<yytext<<endl;}
<processa_autor>[ \t]*\}[ \t]*\n   {cout << "OUT AUTOR" << endl;BEGIN 0;}
<processa_autor>.                 ;

<processa_titulo>[ \t]+              {putchar(' ');}
<processa_titulo>(.+)/(([\"\}],))    {title+=yytext;cout<<"TITULO -->"<<title<<endl;BEGIN 0;}
<processa_titulo>.                 ;
%%
int main(int argc, char *argv[]) {

  FlexLexer* lexer = new yyFlexLexer;
  while(lexer->yylex() != 0);
  //ta->printer();
  return 0;
}
