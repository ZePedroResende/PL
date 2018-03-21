function generateHTML(){
	   print "<HTML>\n<h1>Seja bem-vindo ao mundo encantado de Processamento de Linguagens\n" > "1.html";
	   print "<h3>Numero de Extratos (&ltext&gt) :",countEXT"</h3>\n" > "1.html";
	   print "<h3>Numero de Paragrafos (&ltp&gt) :",countP"</h3>\n" > "1.html";
	   print "<h3>Numero de Frases (&lts&gt) :",countS"</h3>\n" > "1.html";
	   print "\n</HTML>" > "1.html";
	  
}

$1=="<ext" {countEXT++}
$1=="<p" {countP++}
$1 == "<s>" {countS++}

END{ 
	 generateHTML();
	 print countEXT, countP, countS; 
   }
