#ifndef _INCLUDES
#define _INCLUDES
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#endif

void beginHtml(FILE*);
void endHtml(FILE*);

void addWord(FILE*, char*);
void addMean(FILE*, char*);
void addSyn(FILE*, char*);
void addEnglish(FILE*, char*);

