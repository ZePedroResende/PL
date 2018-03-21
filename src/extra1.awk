 /^<s>/ {STATE = 1; next}
 /^<\/s>/ { frase = tolower(frase); frases[frase]++; frase=""; STATE = 0;next}
 /<mwe/ {next;}
 /<\/mwe>/ {next;}

STATE == 1    {frase = frase" "$1 ; next}
END{for (j in frases){print frases[j], j | "sort -nr" };}
