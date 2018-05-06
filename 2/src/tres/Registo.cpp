#include "Registo.h"

Registo::Registo(){

}

Registo::Registo(string t, string y){
    titulo = t;
    year = y;
}

void Registo::setYear(string ano){
    year = ano;
}

void Registo::setTitulo(string t){
    titulo = t;
}

string Registo::getYear(){
    return year;
}

string Registo::getTitulo(){
    return titulo;
}
