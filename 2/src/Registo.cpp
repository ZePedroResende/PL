#include "Registo.h"

Registo::Registo(){

}

Registo::Registo(string t,string j,string e, string p, int y, string m, int v, int n, string pg, string no, string add, string boo, string isb, string edi, string shi, string ur, string abst, string ser, string lan){
    titulo = t;
    journal = j;
    editor = e;
    publisher = p;
    year = y;
    month = m;
    volume = v;
    number = n;
    pages = pg;
    note = no;
    address = add;
    booktitle = boo;
    isbn = isb;
    edition = edi;
    shortin = shi;
    url = ur;
    abstract = abst;
    series = ser;
    lang = lan;
}