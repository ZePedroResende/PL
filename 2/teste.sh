#!/bin/bash
if [ $# -ne 1 ]; then
  echo -e "\033[0;31mUsage: ./teste.sh [FILE TO TEST]\033[0m"
  exit 0
fi
path="../../$1"
mkdir -p html
####################################################
echo -e "\033[0;32mExecuting 1...\033[0m"
cd src/um
../../build/um $path
####################################################
echo -e "\033[0;32mExecuting 2...\033[0m"
cd ../dois
../../build/dois $path
####################################################
echo -e "\033[0;32mExecuting 3...\033[0m"
cd ../tres
../../build/tres "PedroRangelHenriques" $path
####################################################
echo -e "\033[0;32mExecuting 4...\033[0m"
cd ../quatro
../../build/quatro  $path "J\.J\.Almeida" > exemploAutor.dot
../../build/quatro  $path > exemploGlobal.dot
sed '1d' exemploGlobal.dot > tmpfile; mv tmpfile exemploGlobal.dot
dot -Tps  exemploAutor.dot -o graphA.ps
dot -Tps  exemploGlobal.dot -o graphG.ps
####################################################
cd ../../
echo -e "\033[0;32mMaking index...\033[0m"
HTML="html/"
INDEX="html/index.html"
echo "<html><meta charset=\"UTF-8\"><header><h1>Lista de ficheiros</h1></header>" > $INDEX
for filepath in `find "$HTML" -maxdepth 1 -mindepth 1 -type f | sort`; do
  file=`basename $filepath`
  echo "<a href=./$file>$file</a><p>" >> $INDEX
done
echo "</html>" >> $INDEX