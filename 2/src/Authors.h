#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include "Registo.h"

using namespace std;

class Authors{

    private:
        vector<string> autores;
        vector<string> titulos;
        vector<string> books;
    public:
        Authors();
        vector<string> getAutores();
        void addAutor(string);
        void addTitulo(string);
        void addBook(string);
        void makeIndex();
};