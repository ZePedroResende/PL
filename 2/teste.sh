#!/bin/bash
if [ $# -ne 1 ]; then
  echo -e "\033[0;31mUsage: ./teste.sh [FILE TO TEST]\033[0m"
  exit 0
fi
path="../../$1"
make exec
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
# cd ../tres
# 3 here
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