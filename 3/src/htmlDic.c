#include "htmlDic.h"

void beginHtml(FILE* fp){
    printf("%s\n", "ola");
    fprintf(fp, "<html>\n<head>\n<title>Dicionário</title>\n</head>\n<body>\n<div>\n<table>\n<thead><tr><th>Palavra</th>\n<th>Significado</th>\n<th>Sinónimos</th>\n<th>Inglês</th>\n</tr></thead></table></div>\n<table>\n<tbody>");
}

void addWord(FILE* fp, char* w){
    fprintf(fp, "<tr>\n<td>%s</td>\n", w);
}

void addMean(FILE* fp, char* m){
    fprintf(fp, "<td>%s</td>\n<td>", m);
}

void addSyn(FILE* fp, char* s){
    fprintf(fp, "%s\n", s);
}

void addEnglish(FILE* fp, char* e){
    fprintf(fp, "</td>\n<td>%s</td>\n</tr>\n", e);
}

void endHtml(FILE* fp){
    fprintf(fp, "</tbody>\n</table>\n<script src=\"%s\"></script>\n<script src=\"%s\"></script>\n<script src=\"%s\"></script>\n<script src=\"%s\"></script>\n<script src=\"%s\"></script>\n<script>\n$('.js-pscroll').each(function(){\nvar ps = new PerfectScrollbar(this);\n$(window).on('resize', function(){\nps.update();\n})\n});\n</script>\n<script src=\"%s\"></script>\n</body>\n</html>", "../assets/vendor/jquery/jquery-3.2.1.min.js", "../assets/vendor/bootstrap/js/popper.js", "../assets/vendor/bootstrap/js/bootstrap.min.js", "../assets/vendor/select2/select2.min.js", "../assets/vendor/perfect-scrollbar/perfect-scrollbar.min.js", "../assets/js/main.js");
    fclose(fp);
}