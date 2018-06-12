program: texto.l linkedhash.o
	flex texto.l
	gcc  lex.yy.c linkedhash.o -o program

dic: y.tab.o lex.yy.o linkedhash.o
	gcc -o dicionario y.tab.o lex.yy.o linkedhash.o -ll

sttc: sttc.o y.tab.o linkDicionario.o linkTexto.o linkedhash.o html.o
	gcc -o sttc sttc.o y.tab.o linkDicionario.o linkTexto.o linkedhash.o html.o -ll

sttc.o: sttc.c linkTexto.o
	gcc -c sttc.c

linkTexto.o: lexTexto.c y.tab.h
	gcc -c lex.texto.c -o linkTexto.o

lexTexto.c: texto.l
	flex -l -P texto texto.l

y.tab.o: y.tab.c
	gcc -c y.tab.c

linkDicionario.o: lex.yy.c y.tab.h
	gcc -c lex.yy.c -o linkDicionario.o

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

y.tab.c y.tab.h: dicionario.y
	yacc -d dicionario.y

lex.yy.c: dicionario.l y.tab.h
	flex dicionario.l

linkedhash.o: linkedhash.c linkedhash.h
	gcc -c -g -Wall linkedhash.c

html.o: html.c html.h
	gcc -c -g -Wall html.c

clean:
	@rm lex.yy.c >/dev/null 2>&1
	@rm *.o >/dev/null 2>&1
	@rm program >/dev/null 2>&1
