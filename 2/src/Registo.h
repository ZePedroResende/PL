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
        string journal;
        string editor;
        string publisher;
        int year;
        string month;
        int volume;
        int number;
        string pages;
        string note;
        string address;
        string booktitle;
        string isbn;
        string edition;
        string shortin;
        string url;
        string abstract;
        string series;
        string lang;

    public:
        Registo();
        Registo(string,string,string,string,int,string,int,int,string,string,string,string,string,string,string,string,string,string,string);
        
};