#include "linkedhash.h"
#include "y.tab.h"
#include "lexDic.h"
#include "lexTex.h"

void usage();

int main(int argc, char* argv[]){

    if(argc < 2){
        printf("Número de argumentos inválido.\n");
        usage();
        return -1;
    }
    
    parseDicionario(argv[1]);
    lex(argc-1, argv+1);

    return 0;
}

void usage() {
  printf("USAGE: ./sttc <dicionario.dic> [<ficheiro1> <ficheiro2>..]");
}
