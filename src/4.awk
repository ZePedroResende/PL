$0 !~ /^<(.*)?(>)?/ {freq[$1] = "("$4","$5")"}
END{for (j in freq){print freq[j], j | "sort" }}
