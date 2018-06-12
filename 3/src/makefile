program: main.o linkedhash.o
	gcc -o program main.o linkedhash.o

main.o: main.c linkedhash.h
	gcc -c -g -Wall main.c

linkedhash.o: linkedhash.c linkedhash.h
	gcc -c -g -Wall linkedhash.c

dicionary: y.tab.o lex.yy.o linkedhash.o
	gcc -o dic y.tab.o lex.yy.o linkedhash.o -ll

y.tab.o: y.tab.c
	gcc -c y.tab.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

y.tab.c y.tab.h: dic.y
	yacc -d dic.y

lex.yy.c: dicionario.l y.tab.h
	flex dicionario.l


clean:
	@rm *.o >/dev/null 2>&1
	@rm program >/dev/null 2>&1
