BEGIN{FS="\t" }
  /<mwe pos=.*>/{match($0,"[A-Z]+",pos); tmp = pos[0];  st=1; next }

  /<\/mwe>/{str = tolower(str); freq[str]++; tipo[str]= tmp; str="";st= 0;next }

  st==1{str = str" "$1}
END{for (j in freq){print freq[j], j," "tipo[j] | "sort -n"} }
