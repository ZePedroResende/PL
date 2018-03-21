$1=="<ext" {countEXT++}
$1=="<p" {countP++}
$1 == "<s>" {countS++}
END{ print countEXT, countP, countS | "sort -n"; }
