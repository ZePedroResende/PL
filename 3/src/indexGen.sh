#!/bin/bash
echo -e "\033[0;32mMaking index...\033[0m"
HTML="html/"
INDEX="html/index.html"
echo "<html><meta charset=\"UTF-8\"><header><h1>Lista de ficheiros</h1></header>" > $INDEX
for filepath in `find "$HTML" -maxdepth 1 -mindepth 1 -type f -name *.html | sort`; do
  file=`basename $filepath`
  echo "<a href=./$file>$file</a><p>" >> $INDEX
done
echo "</html>" >> $INDEX
