BEGIN{
}

function generateHTML() {
   print "<html>\n<meta charset=\"UTF-8\">\n<header>\n<h1>Lista de frases</h1>\n</header>"> "5.html"
   print "<body><table border='1'>"> "5.html"
   print "<title> Frases implicitas</title>" > "5.html"

   for (i in frases) {
   print "<p>",i ,"</p>" > "5.html"
   }
}


  $0 ~ /^<\/(.*)?(>)?/ {if(frase != ""){frases[frase]++; frase=""};next}
  $0 !~ /^<(.*)?(>)?/ {frase = frase" "$1 ; next}


END{generateHTML();for (j in frases){print frases[j], j | "sort -nr" };}
