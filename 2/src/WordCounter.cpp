#include "words.h"

WordCounter::WordCounter(){

}

bool WordCounter::comparator(pair<int, string> left, pair<int, string> right) {
  if (left.first > right.first) return true;
  if (left.first == right.first && left.second < right.second) return true;
  return false;
}

void WordCounter::printer() {
  for (auto p: categorias) {
    catCount.push_back(pair<int,string>{p.second,p.first});
  }
  sort(catCount.begin(),catCount.end(), comparator);
  for(auto p: catCount) {
    htmlStart();
    cout << p.second << "\t" << p.first << endl;
    htmlEnd();
  }
}

void WordCounter::addWord(string text) {
  ++categorias[text];
}

void WordCounter::htmlStart() {

}

void WordCounter::htmlEnd() {

}