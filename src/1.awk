$1=="<ext" {countEXT++}
$1=="<p" {countP++}
$1 == "<s>" {countS++}
END {
    print "Extensões:" , countEXT; 
    print "Paragrafos:" , countP; 
    print "Frases:",  countS
}
