function generateHTML() {
   print "<html>\n<meta charset=\"UTF-8\">\n<header>\n<h1>Dicionario implicito</h1>\n</header>"> "4.html"
   print "<body><table border='1'>"> "4.html"
   print "<tr><td> Palavra </td><td> Lema  </td><td> Pos </td></tr>"> "4.html"

   for (i in lema) {
   print "<tr><td>", i ,"</td><td>", lema[i],"</td><td>", pos[i], "</td></tr>" |" sort -k2n >>4.html";
   }
}

$0 !~ /^<(.*)?(>)?/ {lema[$1] = $4; pos[$1] = $5}
END{generateHTML();for (j in lema){print j, "("lema[j]","pos[j] ")" | "sort" }}
