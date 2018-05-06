#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <stdio.h>

using namespace std;

class Registo{

    private:
        string titulo;
        string keyword;
        string year;

    public:
        Registo();
        Registo(string,string,string);
        void setYear(string);
        void setKey(string);
        void setTitulo(string);
        string getYear();
        string getKey();
        string getTitulo();
};