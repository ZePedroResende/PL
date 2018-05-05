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
        string autor;
        string titulo;
        string keyword;
        int year;

    public:
        Registo();
        Registo(string,string,string,int);
        
};