BEGIN     {}
$5 == "V"  {freq[$4]++}
END       {for(i in freq) print freq[i], i}
