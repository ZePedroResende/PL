function generateHTML() {
   print "<html>\n<meta charset=\"UTF-8\">\n<header>\n<h1>Lista de Verbos</h1>\n</header>"> "3.html"
   print "<body><table border='1'style='float:left'>"> "3.html"
   print "<tr><td> Frequencia </td><td> Verbo</td></tr>"> "3.html"

   for (i in freq) {
   print "<tr><td>", freq[i],
         "</td><td>", i, "</td></tr>" |" sort -k2nr >> 3.html"
   }
}

$5 == "V"  {freq[$4]++}
END {  generateHTML();
  for(i in freq){print freq[i], i| "sort -rn"}}

