BEGIN{FS="\t" }


function generateHTML() {
   print "<html>\n<meta charset=\"UTF-8\">\n<header>\n<h1>Lista de Multi Word Expression</h1>\n</header>"> "2.html"
   print "<body><table border='1'>"> "2.html"
   print "<tr><td> Frequencia </td><td> MWE </td><td> Tipo </td></tr>"> "2.html"

   for (i in freq) {
   print "<tr><td>",freq[i],"</td><td>",i,"</td><td>",tipo[i],"</td></tr>" |" sort -k2nr >> 2.html"
   }
}

  /<mwe pos=.*>/{match($0,"[A-Z]+",pos); tmp = pos[0];  st=1; next }

  /<\/mwe>/{if(str != ""){str = tolower(str); freq[str]++; tipo[str]= tmp}; str="";st= 0;next }

  st==1{str = str" "$1; next}
END{generateHTML(); for (j in freq){print freq[j], j," "tipo[j] | "sort -n"} ; }
