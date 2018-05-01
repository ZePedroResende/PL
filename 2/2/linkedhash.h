#include <string.h>
#include <stdlib.h>

typedef struct nlist{ /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    int count; /* replacement text */
} *Nlist;

#define HASHSIZE 101
static Nlist hashtab[HASHSIZE]; /* pointer table */

unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
      hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    Nlist np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
          return np; /* found */
    return NULL; /* not found */
}

 void install(char *name)
{
    Nlist np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        hashval = hash(name);
        np->name = name;
        np->count = 1;
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else{
        np->count++;
    }
}

