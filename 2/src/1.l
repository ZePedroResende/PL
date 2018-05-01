%option c++
%{
#include "words.h"
int i=0;
unordered_map<string,int> categorias;
vector<pair<int, string> > catCount;
extern "C" int yylex();
%}

STRING             [a-zA-Z]

%%

[ \n\t]                 ;
\@{STRING}+\{           {yytext[yyleng-1]='\0';yytext=yytext+1;++categorias[yytext];}
.                       ;

%%

int main(int argc, char *argv[]) {

  yylex();
  for (auto p: categorias) {
    catCount.push_back(pair<int,string>{p.second,p.first});
  }
  sort(catCount.begin(),catCount.end(), F());
  for(auto p: catCount) {
    cout << p.second << "\t" << p.first << endl;
  }

}
