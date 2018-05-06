#include "Authors.h"

Authors::Authors(){

}

void Authors::addAutor(string a){
    autores.push_back(a);
}

void Authors::addTitulo(string a){
    titulos.push_back(a);
}

void Authors::addYear(string a){
    years.push_back(a);
}

void Authors::addRegisto(){
    string tit, ye;
    if(titulos.size()>0) tit = titulos.front();
    else tit="sem titulo";
    if(years.size()>0) ye = years.front();
    else ye = "sem ano";
    Registo* r = new Registo(tit,ye);
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
}

void Authors::htmlStart(){
    file << "<!DOCTYPE html><html lang=\"en\">" << endl;
    file << "<head>" << endl;
	file << "<title>Índice</title>" <<endl;
	file << "<title>Índice</title>" <<endl;
	file << "<title>Índice</title>" <<endl;
	file << "<title>Índice</title>" <<endl;
	file << "<meta charset=\"UTF-8\">" <<endl;
	file << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">" <<endl;
    file << "<!--===============================================================================================-->	" <<endl;
	file << "<link rel=\"icon\" type=\"image/png\" href=\"assets/images/icons/favicon.ico\"/>" <<endl;
    file << "<!--===============================================================================================-->" <<endl;
	file << "<link rel=\"stylesheet\" type=\"text/css\" href=\"assets/vendor/bootstrap/css/bootstrap.min.css\">" <<endl;
    file << "<!--===============================================================================================-->" <<endl;
	file << "<link rel=\"stylesheet\" type=\"text/css\" href=\"assets/fonts/font-awesome-4.7.0/css/font-awesome.min.css\">" << endl;
    file << "<!--===============================================================================================-->" << endl;
	file << "<link rel=\"stylesheet\" type=\"text/css\" href=\"assets/vendor/animate/animate.css\">" << endl;
    file << "<!--===============================================================================================-->" << endl;
	file << "<link rel=\"stylesheet\" type=\"text/css\" href=\"assets/vendor/select2/select2.min.css\">" << endl;
    file << "<!--===============================================================================================-->" << endl;
	file << "<link rel=\"stylesheet\" type=\"text/css\" href=\"assets/vendor/perfect-scrollbar/perfect-scrollbar.css\">" << endl;
    file << "<!--===============================================================================================-->" << endl;
	file << "<link rel=\"stylesheet\" type=\"text/css\" href=\"assets/css/util.css\">" << endl;
	file << "<link rel=\"stylesheet\" type=\"text/css\" href=\"assets/css/main.css\">" << endl;
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
	file << "<th class=\"cell100 column1\">Título</th>" << endl;
	file << "<th class=\"cell100 column2\">Ano</th>" << endl;
	file << "</tr>" << endl;
	file << "</thead>" << endl;
	file << "</table>" << endl;
	file << "</div>" << endl;
    file << "<div class=\"table100-body js-pscroll\">" << endl;
	file << "<table>" << endl;
	file << "<tbody>" << endl;
}

void Authors::htmlEnd() {
    file << "</tbody>" << endl;
	file << "</table>" << endl;
	file << "</div>" << endl;
	file << "</div>" << endl;
	file << "</div>" << endl;
	file << "</div>" << endl;
	file << "</div>" << endl;
    file << "<!--===============================================================================================-->	" << endl;
	file << "<script src=\"assets/vendor/jquery/jquery-3.2.1.min.js\"></script>" << endl;
    file << "<!--===============================================================================================-->" << endl;
	file << "<script src=\"assets/vendor/bootstrap/js/popper.js\"></script>" << endl;
	file << "<script src=\"assets/vendor/bootstrap/js/bootstrap.min.js\"></script>" << endl;
    file << "<!--===============================================================================================-->" << endl;
	file << "<script src=\"assets/vendor/select2/select2.min.js\"></script>" << endl;
    file << "<!--===============================================================================================-->" << endl;
	file << "<script src=\"assets/vendor/perfect-scrollbar/perfect-scrollbar.min.js\"></script>" << endl;
	file << "<script>" << endl;
	file << "$('.js-pscroll').each(function(){" << endl;
	file << "var ps = new PerfectScrollbar(this);" << endl;
    file << "$(window).on('resize', function(){" << endl;
	file << "ps.update();" << endl;
	file << "})" << endl;
	file << "});" << endl;		
	file << "</script>" << endl;
    file << "<!--===============================================================================================-->" << endl;
	file << "<script src=\"assets/js/main.js\"></script>" << endl;
    file << "</body>" << endl;
    file << "</html>" << endl;
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
        file.open("../../html/3.html", ios_base::trunc);
        htmlStart();
        map<string,Registo*> v = m->second;
        for(map<string,Registo*>::const_iterator mr = v.begin(); mr!=v.end(); ++mr){
            file << "<tr class=\"row100 body\">" << endl;
		    file << "<td class=\"cell100 column1\">" << mr->first << "</td>" << endl;
		    file << "<td class=\"cell100 column2\">" << mr->second->getYear() << "</td>" << endl;
		    file << "</tr>" << endl;
        }
        htmlEnd();
    }

}