#ifndef _INCLUDES
#define _INCLUDES
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#endif

void htmlStart(FILE*, char*);
void textEnd(FILE*);
void htmlEnd(FILE*);

void htmlApenStart(FILE*, char*);
void htmlApenEnd(FILE* out);
