#!/bin/bash
make clean
make tres
mkdir -p ../../html
../../build/tres "PedroRangelHenriques" < ../../files/exemplo-latin1.bib