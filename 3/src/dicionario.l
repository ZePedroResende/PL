%x mean syn english word

%{
#include <stdio.h>
char* mean, syn, english, w;
%}

STRING ([a-zA-Z0-9]|[áàâãéèêíóôúçñÁÀÂÃÉÈÍÓÔÕÚÇ,-.]|\ )

%%
{STRING}+\{                                   {yytext[yyleng-1]='\0';
                                               yylval.texto = strdup(yytext);
                                               return w;
                                               BEGIN (word);}

<word>\}                                      {BEGIN 0;
                                               }

<word>\n                                      ;

<word>[\ \t]*mean:[\ \t]*\"                   {BEGIN (mean);}

<mean>\"                                      {BEGIN (word);}

<mean>\n                                      ;

<mean>{STRING}+                               {yylval.texto = strdup(yytext); return MEAN;}

<word>[\ \t]*syn:[\ \t]*\"                    {BEGIN (syn);}

<syn>\"                                       {BEGIN (word);}

<syn>\n                                       ;

<syn>{STRING}+                                {yylval.texto = strdup(yytext); return SYN;}

<word>[\ \t]*english:[\ \t]*\"                {BEGIN (english);}

<english>\"                                   {BEGIN (word);}

<english>\n                                   ;

<english>{STRING}+                            {yylval.texto = strdup(yytext); return ENGLISH;}

.|\n                                          ;
%%

int yywrap(){
	return 1;
}

/*int main(int argc, char *argv[]) {
    int s;
    while(s=yylex()){
        printf("%d\n",s);
    }
    
    return 0;
}*/
