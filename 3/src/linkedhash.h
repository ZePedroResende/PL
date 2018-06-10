#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct SIN {
  struct SIN *next;
  char *name;
} *sin;

typedef struct NOME {
  char *mean;
  sin sinonimos;
  char *english;
  int indice;
  int counter;

} *nome;

typedef struct NLIST { /* table entry: */
    struct NLIST *next; /* next entry in chain */
    char *name; /* defined name */
    nome defn; /* replacement text */
} *nlist;



#define HASHSIZE 101
nlist hashtab[HASHSIZE]; /* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s);

/* lookup: look for s in hashtab */
nlist lookup(char *s);

/* install: put (name, defn) in hashtab */
nlist install(char *name, nome defn);

char *strdupl(char *s); /* make a duplicate of s */


nome new_nome();
void add_mean(nome *n, char* mean);
void add_english(nome *n, char* english);
void add_sin(nome *n, char* syn);
nome lookup_nome(char *s);
nlist get_used_list();
void add_footnote_list(nome *n, nlist *l);
void print_footnote(FILE *out);
void reset_indice();
void print_used_list(FILE *out);
