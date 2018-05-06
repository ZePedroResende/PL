#!/bin/bash
make clean
make
../build/quatro  ../../files/exemplo-latin1.bib "J\.J\.Almeida" > exemploAutor.dot
../build/quatro  ../../files/exemplo-latin1.bib > exemploGlobal.dot
sed '1d' exemploGlobal.dot > tmpfile; mv tmpfile exemploGlobal.dot
dot -Tps  exemploAutor.dot -o graphA.ps
dot -Tps  exemploGlobal.dot -o graphG.ps
