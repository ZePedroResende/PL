#include "Authors.h"

Authors::Authors(){

}

void Authors::addAutor(string a){
    autores.push_back(a);
}

void Authors::addTitulo(string a){
    titulos.push_back(a);
}

void Authors::addKey(string a){
    keys.push_back(a);
}

void Authors::addYear(string a){
    years.push_back(a);
}

void Authors::addRegisto(){
    string tit, ye, kk;
    if(titulos.size()>0) tit = titulos.front();
    else tit="sem titulo";
    if(years.size()>0) ye = years.front();
    else ye = "sem ano";
    if(keys.size()>0) kk = keys.front();
    else kk = "sem key";
    Registo* r = new Registo(tit,kk,ye);
    for(string s: autores){
        if(indice.find(s)!=indice.end()){
            if(indice[s].find(titulos.front())==indice[s].end()){
                indice[s].insert(pair<string,Registo*>(titulos.front(),r));
                //indice[s][r->getTitulo()] = r;
            }
        }
        else{
            map<string,Registo*> reg;
            reg.insert(pair<string,Registo*>(titulos.front(),r));
            indice.insert(pair<string,map<string,Registo*>>(s,reg));
        }
        
    }
    autores.clear();
    titulos.clear();
    years.clear();
    keys.clear();
}

void htmlStart(){
    "index.html" < "<!DOCTYPE html><html lang=\"en\">\n"
    "index.html" << "<head>" << endl;
	"index.html" << "<title>Índice</title>" <<endl;
	"index.html" << "<title>Índice</title>" <<endl;
	"index.html" << "<title>Índice</title>" <<endl;
	"index.html" << "<title>Índice</title>" <<endl;
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
	cout << "<th class=\"cell100 column1\">Título</th>" << endl;
	cout << "<th class=\"cell100 column2\">Ano</th>" << endl;
	cout << "</tr>" << endl;
	cout << "</thead>" << endl;
	cout << "</table>" << endl;
	cout << "</div>" << endl;
  cout << "<div class=\"table100-body js-pscroll\">" << endl;
	cout << "<table>" << endl;
	cout << "<tbody>" << endl;
}

void htmlEnd() {
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

void Authors::makeIndex(char* autor){
    /*for(map<string,map<string,Registo*>>::const_iterator it = indice.begin(); it != indice.end(); ++it){
        cout << it->first << endl;
        for(map<string,Registo*>::const_iterator v = it->second.begin(); v!= it->second.end(); ++v){
            cout << " --> TITULO: " << v->first << endl;
            cout << " --> ANO: " << v->second->getYear() << endl;
        }
    }*/

    string aut = (string) autor;
    map<string,map<string,Registo*>>::const_iterator m = indice.find(aut);
    if(m == indice.end()){
        cout << "Autor não encontrado!" << endl;
    }
    else{
        htmlStart();
        map<string,Registo*> v = m->second;
        for(map<string,Registo*>::const_iterator mr = v.begin(); mr!=v.end(); ++mr){
            cout << "<tr class=\"row100 body\">" << endl;
		    cout << "<td class=\"cell100 column1\">" << mr->first << "</td>" << endl;
		    cout << "<td class=\"cell100 column2\">" << mr->second->getYear() << "</td>" << endl;
		    cout << "</tr>" << endl;
        }
        htmlEnd();
    }

}