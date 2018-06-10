#include"linkedhash.h"

int state = 0;

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
      hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
nlist lookup(char *s)
{
    nlist np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
          return np; /* found */
    return NULL; /* not found */
}

/* install: put (name, defn) in hashtab */
nlist install(char *name, nome defn)
{
    nlist np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct NLIST *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdupl(name)) == NULL)
          return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else /* already there */
        free((void *) np->defn); /*free previous defn */
    if ((np->defn = defn) == NULL)
       return NULL;
    return np;
}

char *strdupl(char *s) /* make a duplicate of s */
{
    char *p;
    p = (char *) malloc(strlen(s)+1); /* +1 for ’\0’ */
    if (p != NULL)
       strcpy(p, s);
    return p;
}


nome new_nome(){
  nome n = (struct NOME *) malloc(sizeof(struct NOME));
  n->mean = NULL;
  n->sinonimos = NULL;
  n->english = NULL;
  n->counter = 0;
  n->indice = -1;
  return n;
}

void add_mean(nome *n, char* mean){
  (*n)->mean = strdupl(mean);
}

void add_english(nome *n, char* english){
  (*n)->english = strdupl(english);
}

void add_sin(nome *n, char* syn){
  sin* s = &(*n)->sinonimos;

  while((*s) != NULL){
    s = &(*s)->next;
  }

  *s = (struct SIN *) malloc(sizeof(sin));
  (*s)->name = strdupl(syn);
  (*s)->next = NULL;
}

nome lookup_nome(char *s){
    nlist np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0){
            np->defn->counter++;
            if(np->defn->indice == -1){
              state++;
              np->defn->indice = state;
            }
            return np->defn; /* found */
        }
    return NULL; /* not found */
}

void add_to_list(char *n, nlist *l){
  nlist nl = NULL;

  while((*l) != NULL && strcmp((*l)->name,n) < 0){
    l = &(*l)->next;
  }

  nl = (struct NLIST *) malloc(sizeof(struct NLIST));
  (nl)->name = n;
  (nl)->next = *l;
  *l = nl;
}

nlist get_used_list(){
    nlist result = NULL;
    nlist np;
    int counter = 0;
    for(;counter < HASHSIZE ; counter++){
      for (np = hashtab[counter]; np != NULL; np = np->next)
          if (np->defn->counter > 0){
              add_to_list((np->name),&result);
          }
    }
  return result;
}

void print_used_list(FILE *out){
    nlist res = get_used_list();
    nlist* result = &res;
    while((*result) != NULL){
      fprintf(out,"<p> %s usado %d vezes; ",
          (*result)->name, (*result)->defn->counter);
      fprintf(out,"</p>\n");

      result = &(*result)->next;


    }
}

void add_footnote_list(nome *n, nlist *l){
  nlist nl = NULL;

  while((*l) != NULL && (*l)->defn->indice < (*n)->indice ){
    l = &(*l)->next;
  }

  nl = (struct NLIST *) malloc(sizeof(struct NLIST));
  (nl)->defn = *n;
  (nl)->next = *l;
  *l = nl;
}

void print_footnote(FILE *out){
    nlist res = NULL;
    nlist np= NULL;
    int counter = 0;
    for(;counter < HASHSIZE ; counter++){
      for (np = hashtab[counter]; np != NULL; np = np->next)
          if (np->defn->counter > 0){
              add_footnote_list(&(np->defn),&res);
          }
    }
    nlist* result = &res;
    while((*result) != NULL){
      fprintf(out,"<p id=\"section%d\">[%d]significado: %s; ingles: %s;",
          (*result)->defn->indice, (*result)->defn->indice,
          (*result)->defn->mean,(*result)->defn->english);

      fprintf(out," sinon:");
      sin *sinon = &((*result)->defn->sinonimos);
      while((*sinon) != NULL){
        fprintf(out,"%s,",(*sinon)->name);
        sinon = &(*sinon)->next;
      }

      fprintf(out,"</p>\n");

      result = &(*result)->next;


    }
}

void reset_indice(){
    nlist result = NULL;
    nlist np;
    int counter = 0;
    for(;counter < HASHSIZE ; counter++){
      for (np = hashtab[counter]; np != NULL; np = np->next)
          if (np->defn->indice != -1){
            np->defn->indice = -1;
          }
    }
}