function generateHTML() {
   print "<html>\n<meta charset=\"UTF-8\">\n<header>\n<h1>Lista de frases</h1>\n</header>"> "5.html"
   print "<body><table border='1'>"> "5.html"
   print "<title> Frases implicitas</title>" > "5.html"

   for (i in frases) {
   print "<p>",i ,"</p>" |" sort -k2nr >> 5.html"
   }
}

 /^<s>/ {STATE = 1; next}
 /^<\/s>/ { frase = tolower(frase); frases[frase]++; frase=""; STATE = 0;next}
 /<mwe/ {next;}
 /<\/mwe>/ {next;}

STATE == 1    {frase = frase" "$1 ; next}
END{generateHTML();for (j in frases){print frases[j], j | "sort -nr" };}
