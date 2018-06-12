#include "html.h"

void htmlStart(FILE* out, char* title){
  fprintf(out,"<!-- HTML 4 -->\n<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n<!-- HTML5 -->\n<meta charset=\"utf-8\"/>\n<html>");
  fprintf(out, "<head>\n<link rel=\"stylesheet\" href=\"style.css\">\n<title>%s</title></head>\n<body>", title);
  fprintf(out, "<h1 class=\"hellopeople\">%s</h1>\n<div class=\"entry-content\">", title);
}

void textEnd(FILE* out){
  fprintf(out, "</div>");
}

void htmlEnd(FILE* out){
  fprintf(out, "</html>");
}

/*
  HTML do Apêndice
*/
void htmlApenStart(FILE* out, char* title){
  fprintf(out, "<!DOCTYPE html><html lang=\"en\">" );
  fprintf(out, "<head>" );
	fprintf(out, "<title>%s</title>", title);
	fprintf(out, "<meta charset=\"UTF-8\">" );
	fprintf(out, "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">" );
  fprintf(out, "<!--===============================================================================================-->	" );
	fprintf(out, "<link rel=\"icon\" type=\"image/png\" href=\"../assets/images/icons/favicon.ico\"/>" );
  fprintf(out, "<!--===============================================================================================-->" );
	fprintf(out, "<link rel=\"stylesheet\" type=\"text/css\" href=\"../assets/vendor/bootstrap/css/bootstrap.min.css\">" );
  fprintf(out, "<!--===============================================================================================-->" );
	fprintf(out, "<link rel=\"stylesheet\" type=\"text/css\" href=\"../assets/fonts/font-awesome-4.7.0/css/font-awesome.min.css\">" );
  fprintf(out, "<!--===============================================================================================-->" );
	fprintf(out, "<link rel=\"stylesheet\" type=\"text/css\" href=\"../assets/vendor/animate/animate.css\">" );
  fprintf(out, "<!--===============================================================================================-->" );
	fprintf(out, "<link rel=\"stylesheet\" type=\"text/css\" href=\"../assets/vendor/select2/select2.min.css\">" );
  fprintf(out, "<!--===============================================================================================-->" );
	fprintf(out, "<link rel=\"stylesheet\" type=\"text/css\" href=\"../assets/vendor/perfect-scrollbar/perfect-scrollbar.css\">" );
  fprintf(out, "<!--===============================================================================================-->" );
	fprintf(out,"<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">");
  fprintf(out, "<!--===============================================================================================-->" );
	fprintf(out, "<link rel=\"stylesheet\" type=\"text/css\" href=\"../assets/css/util.css\">" );
	fprintf(out, "<link rel=\"stylesheet\" type=\"text/css\" href=\"../assets/css/main.css\">" );
  fprintf(out, "<!--===============================================================================================-->" );
  fprintf(out, "</head>" );
  fprintf(out, "<body>" );
	fprintf(out, "<h1 class=\"hellopeople2\">%s</h1>\n", title);
	fprintf(out, "<div class=\"limiter\">" );
	fprintf(out, "<div class=\"container-table100\">" );
	fprintf(out, "<div class=\"wrap-table100\">" );
	fprintf(out, "<div class=\"table100 ver1 m-b-110\">" );
	fprintf(out, "<div class=\"table100-head\">" );
	fprintf(out, "<table>" );
	fprintf(out, "<thead>" );
	fprintf(out, "<tr class=\"row100 head\">" );
	fprintf(out, "<th class=\"cell100 column1\">Palavra</th>" );
	fprintf(out, "<th class=\"cell100 column2\">Frequência</th>" );
	fprintf(out, "</tr>" );
	fprintf(out, "</thead>" );
	fprintf(out, "</table>" );
	fprintf(out, "</div>" );
  fprintf(out, "<div class=\"table100-body js-pscroll\">" );
	fprintf(out, "<table>" );
	fprintf(out, "<tbody>" );
}

void htmlApenEnd(FILE* out){
  fprintf(out, "</tbody>" );
	fprintf(out, "</table>" );
	fprintf(out, "</div>" );
	fprintf(out, "</div>" );
	fprintf(out, "</div>" );
	fprintf(out, "</div>" );
	fprintf(out, "</div>" );
  fprintf(out, "<!--===============================================================================================-->	" );
	fprintf(out, "<script src=\"../assets/vendor/jquery/jquery-3.2.1.min.js\"></script>" );
  fprintf(out, "<!--===============================================================================================-->" );
	fprintf(out, "<script src=\"../assets/vendor/bootstrap/js/popper.js\"></script>" );
	fprintf(out, "<script src=\"../assets/vendor/bootstrap/js/bootstrap.min.js\"></script>" );
  fprintf(out, "<!--===============================================================================================-->" );
	fprintf(out, "<script src=\"../assets/vendor/select2/select2.min.js\"></script>" );
  fprintf(out, "<!--===============================================================================================-->" );
	fprintf(out, "<script src=\"../assets/vendor/perfect-scrollbar/perfect-scrollbar.min.js\"></script>" );
	fprintf(out, "<script>" );
	fprintf(out, "$('.js-pscroll').each(function(){" );
	fprintf(out, "var ps = new PerfectScrollbar(this);" );
  fprintf(out, "$(window).on('resize', function(){" );
	fprintf(out, "ps.update();" );
	fprintf(out, "})" );
	fprintf(out, "});" );		
	fprintf(out, "</script>" );
  fprintf(out, "<!--===============================================================================================-->" );
	fprintf(out, "<script src=\"../assets/js/main.js\"></script>" );
  fprintf(out, "</body>" );
  fprintf(out, "</html>" );
}
