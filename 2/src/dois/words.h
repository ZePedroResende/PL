#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include <stdio.h>

using namespace std;

class TextAnalizer {
  private:
    unordered_map<string,int> categorias;
    vector<pair<int, string> > catCount;
    ofstream file;
    map<string,tuple<string,string,string>> catInfo;
    void htmlStart();
    void htmlMiddle();
    void htmlEnd();
  public:
    TextAnalizer();
    void printer();
    static bool comparator(pair<int, string>, pair<int, string>);
    void addWord(string);
    void addInfo(string,string,string,string);
};
