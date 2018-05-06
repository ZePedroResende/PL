#include "words.h"

WordCounter::WordCounter(){

}

bool WordCounter::comparator(pair<int, string> left, pair<int, string> right) {
  if (left.first > right.first) return true;
  if (left.first == right.first && left.second < right.second) return true;
  return false;
}

void WordCounter::printer() {
  file.open("../../html/1.html", ios_base::trunc);
  for (auto p: categorias) {
    catCount.push_back(pair<int,string>{p.second,p.first});
  }
  sort(catCount.begin(),catCount.end(), comparator);
	if (!file.is_open()) {
    cout << "Error while opening file 1.html" << endl;
  } else {
  	htmlStart();
  	for(auto p: catCount) {
    	file << "<tr class=\"row100 body\">" << endl;
			file << "<td class=\"cell100 column1\">" << p.second << "</td>" << endl;
			file << "<td class=\"cell100 column2\">" << p.first << "</td>" << endl;
			file << "</tr>" << endl;
  	}
		htmlEnd();
	}
}

void WordCounter::addWord(string text) {
	transform(text.begin(), text.end(), text.begin(), ::tolower);
  ++categorias[text];
}

void WordCounter::htmlStart() {
  file << "<!DOCTYPE html><html lang=\"en\">" << endl;
  file << "<head>" << endl;
	file << "<title>Categorias</title>" <<endl;
	file << "<meta charset=\"UTF-8\">" <<endl;
	file << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">" <<endl;
  file << "<!--===============================================================================================-->	" <<endl;
	file << "<link rel=\"icon\" type=\"image/png\" href=\"../assets/images/icons/favicon.ico\"/>" <<endl;
  file << "<!--===============================================================================================-->" <<endl;
	file << "<link rel=\"stylesheet\" type=\"text/css\" href=\"../assets/vendor/bootstrap/css/bootstrap.min.css\">" <<endl;
  file << "<!--===============================================================================================-->" <<endl;
	file << "<link rel=\"stylesheet\" type=\"text/css\" href=\"../assets/fonts/font-awesome-4.7.0/css/font-awesome.min.css\">" << endl;
  file << "<!--===============================================================================================-->" << endl;
	file << "<link rel=\"stylesheet\" type=\"text/css\" href=\"../assets/vendor/animate/animate.css\">" << endl;
  file << "<!--===============================================================================================-->" << endl;
	file << "<link rel=\"stylesheet\" type=\"text/css\" href=\"../assets/vendor/select2/select2.min.css\">" << endl;
  file << "<!--===============================================================================================-->" << endl;
	file << "<link rel=\"stylesheet\" type=\"text/css\" href=\"../assets/vendor/perfect-scrollbar/perfect-scrollbar.css\">" << endl;
  file << "<!--===============================================================================================-->" << endl;
	file << "<link rel=\"stylesheet\" type=\"text/css\" href=\"../assets/css/util.css\">" << endl;
	file << "<link rel=\"stylesheet\" type=\"text/css\" href=\"../assets/css/main.css\">" << endl;
  file << "<!--===============================================================================================-->" << endl;
  file << "</head>" << endl;
  file << "<body>" << endl;
	file << "<div class=\"limiter\">" << endl;
	file << "<div class=\"container-table100\">" << endl;
	file << "<div class=\"wrap-table100\">" << endl;
	file << "<div class=\"table100 ver1 m-b-110\">" << endl;
	file << "<div class=\"table100-head\">" << endl;
	file << "<table>" << endl;
	file << "<thead>" << endl;
	file << "<tr class=\"row100 head\">" << endl;
	file << "<th class=\"cell100 column1\">Categorias</th>" << endl;
	file << "<th class=\"cell100 column2\">Frequência</th>" << endl;
	file << "</tr>" << endl;
	file << "</thead>" << endl;
	file << "</table>" << endl;
	file << "</div>" << endl;
  file << "<div class=\"table100-body js-pscroll\">" << endl;
	file << "<table>" << endl;
	file << "<tbody>" << endl;
}

void WordCounter::htmlEnd() {
  file << "</tbody>" << endl;
	file << "</table>" << endl;
	file << "</div>" << endl;
	file << "</div>" << endl;
	file << "</div>" << endl;
	file << "</div>" << endl;
	file << "</div>" << endl;
  file << "<!--===============================================================================================-->	" << endl;
	file << "<script src=\"../assets/vendor/jquery/jquery-3.2.1.min.js\"></script>" << endl;
  file << "<!--===============================================================================================-->" << endl;
	file << "<script src=\"../assets/vendor/bootstrap/js/popper.js\"></script>" << endl;
	file << "<script src=\"../assets/vendor/bootstrap/js/bootstrap.min.js\"></script>" << endl;
  file << "<!--===============================================================================================-->" << endl;
	file << "<script src=\"../assets/vendor/select2/select2.min.js\"></script>" << endl;
  file << "<!--===============================================================================================-->" << endl;
	file << "<script src=\"../assets/vendor/perfect-scrollbar/perfect-scrollbar.min.js\"></script>" << endl;
	file << "<script>" << endl;
	file << "$('.js-pscroll').each(function(){" << endl;
	file << "var ps = new PerfectScrollbar(this);" << endl;
  file << "$(window).on('resize', function(){" << endl;
	file << "ps.update();" << endl;
	file << "})" << endl;
	file << "});" << endl;		
	file << "</script>" << endl;
  file << "<!--===============================================================================================-->" << endl;
	file << "<script src=\"../assets/js/main.js\"></script>" << endl;
  file << "</body>" << endl;
  file << "</html>" << endl;
}
