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
  htmlStart();
  for(auto p: catCount) {
    cout << "<tr class=\"row100 body\">" << endl;
		cout << "<td class=\"cell100 column1\">" << p.second << "</td>" << endl;
		cout << "<td class=\"cell100 column2\">" << p.first << "</td>" << endl;
		cout << "</tr>" << endl;
  }
  htmlEnd();
}

void WordCounter::addWord(string text) {
  ++categorias[text];
}

void WordCounter::htmlStart() {
  cout << "<!DOCTYPE html><html lang=\"en\">" << endl;
  cout << "<head>" << endl;
	cout << "<title>Categories</title>" <<endl;
	cout << "<meta charset=\"UTF-8\">" <<endl;
	cout << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">" <<endl;
  cout << "<!--===============================================================================================-->	" <<endl;
	cout << "<link rel=\"icon\" type=\"image/png\" href=\"assets/images/icons/favicon.ico\"/>" <<endl;
  cout << "<!--===============================================================================================-->" <<endl;
	cout << "<link rel=\"stylesheet\" type=\"text/css\" href=\"assets/vendor/bootstrap/css/bootstrap.min.css\">" <<endl;
  cout << "<!--===============================================================================================-->" <<endl;
	cout << "<link rel=\"stylesheet\" type=\"text/css\" href=\"assets/fonts/font-awesome-4.7.0/css/font-awesome.min.css\">" << endl;
  cout << "<!--===============================================================================================-->" << endl;
	cout << "<link rel=\"stylesheet\" type=\"text/css\" href=\"assets/vendor/animate/animate.css\">" << endl;
  cout << "<!--===============================================================================================-->" << endl;
	cout << "<link rel=\"stylesheet\" type=\"text/css\" href=\"assets/vendor/select2/select2.min.css\">" << endl;
  cout << "<!--===============================================================================================-->" << endl;
	cout << "<link rel=\"stylesheet\" type=\"text/css\" href=\"assets/vendor/perfect-scrollbar/perfect-scrollbar.css\">" << endl;
  cout << "<!--===============================================================================================-->" << endl;
	cout << "<link rel=\"stylesheet\" type=\"text/css\" href=\"assets/css/util.css\">" << endl;
	cout << "<link rel=\"stylesheet\" type=\"text/css\" href=\"assets/css/main.css\">" << endl;
  cout << "<!--===============================================================================================-->" << endl;
  cout << "</head>" << endl;
  cout << "<body>" << endl;
	
	cout << "<div class=\"limiter\">" << endl;
	cout << "<div class=\"container-table100\">" << endl;
	cout << "<div class=\"wrap-table100\">" << endl;
	cout << "<div class=\"table100 ver1 m-b-110\">" << endl;
	cout << "<div class=\"table100-head\">" << endl;
	cout << "<table>" << endl;
	cout << "<thead>" << endl;
	cout << "<tr class=\"row100 head\">" << endl;
	cout << "<th class=\"cell100 column1\">Categorias</th>" << endl;
	cout << "<th class=\"cell100 column2\">Frequência</th>" << endl;
	cout << "</tr>" << endl;
	cout << "</thead>" << endl;
	cout << "</table>" << endl;
	cout << "</div>" << endl;
  cout << "<div class=\"table100-body js-pscroll\">" << endl;
	cout << "<table>" << endl;
	cout << "<tbody>" << endl;
}

void WordCounter::htmlEnd() {
  cout << "</tbody>" << endl;
	cout << "</table>" << endl;
	cout << "</div>" << endl;
	cout << "</div>" << endl;
	cout << "</div>" << endl;
	cout << "</div>" << endl;
	cout << "</div>" << endl;
  cout << "<!--===============================================================================================-->	" << endl;
	cout << "<script src=\"assets/vendor/jquery/jquery-3.2.1.min.js\"></script>" << endl;
  cout << "<!--===============================================================================================-->" << endl;
	cout << "<script src=\"assets/vendor/bootstrap/js/popper.js\"></script>" << endl;
	cout << "<script src=\"assets/vendor/bootstrap/js/bootstrap.min.js\"></script>" << endl;
  cout << "<!--===============================================================================================-->" << endl;
	cout << "<script src=\"assets/vendor/select2/select2.min.js\"></script>" << endl;
  cout << "<!--===============================================================================================-->" << endl;
	cout << "<script src=\"assets/vendor/perfect-scrollbar/perfect-scrollbar.min.js\"></script>" << endl;
	cout << "<script>" << endl;
	cout << "$('.js-pscroll').each(function(){" << endl;
	cout << "var ps = new PerfectScrollbar(this);" << endl;
  cout << "$(window).on('resize', function(){" << endl;
	cout << "ps.update();" << endl;
	cout << "})" << endl;
	cout << "});" << endl;		
	cout << "</script>" << endl;
  cout << "<!--===============================================================================================-->" << endl;
	cout << "<script src=\"assets/js/main.js\"></script>" << endl;
  cout << "</body>" << endl;
  cout << "</html>" << endl;
}