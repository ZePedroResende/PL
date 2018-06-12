#include "html.h"

void htmlStart(FILE* out){
  fprintf(out,"<!-- HTML 4 -->\n<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n<!-- HTML5 -->\n<meta charset=\"utf-8\"/>");
}
