function makeIndex() {
  print "<html>\n<meta charset=\"UTF-8\"><header><h1>Lista de ficheiros</h1></header>" > "index.html"
  print "<a href=./1.html>Extratos, Parágrafos e Frases</a><p> " > "index.html"
  print "<a href=./2.html>Lista de Multi Word Expressions</a><p>" > "index.html"
  print "<a href=./3.html>Lista de Verbos</a><p>" > "index.html"
  print "<a href=./4.html>Dicionário Implícito</a><p> " > "index.html"
  print "<a href=./5.html>Frases</a><p> " > "index.html"
  print "</html>" > "index.html"
}

BEGIN {
    system("awk -f ./1.awk ../files/micro-Cetempublico01.txt")
    system("awk -f ./2.awk ../files/micro-Cetempublico01.txt")
    system("awk -f ./3.awk ../files/micro-Cetempublico01.txt")
    system("awk -f ./4.awk ../files/micro-Cetempublico01.txt")
    system("awk -f ./extra1.awk ../files/micro-Cetempublico01.txt")
}

END {
  makeIndex()
}



