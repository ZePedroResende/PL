#!/bin/bash
if [ $# -ne 1 ]; then
  echo "Usage: ./teste.sh [FILE TO TEST]"
  exit 0
fi
path="../../$1"
make exec
mkdir -p html
####################################################
echo "Executing 1..."
cd src/um
../../build/um $path
####################################################
echo "Executing 2..."
cd ../dois
../../build/dois $path
####################################################
echo "Executing 3..."
# cd ../tres
# 3 here
####################################################
echo "Executing 4..."
cd ../quatro
../../build/quatro  $path "J\.J\.Almeida" > exemploAutor.dot
../../build/quatro  $path > exemploGlobal.dot
sed '1d' exemploGlobal.dot > tmpfile; mv tmpfile exemploGlobal.dot
dot -Tps  exemploAutor.dot -o graphA.ps
dot -Tps  exemploGlobal.dot -o graphG.ps
####################################################
cd ../../