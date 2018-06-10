program: texto.l linkedhash.o
	flex texto.l
	gcc  lex.yy.c linkedhash.o -o program

linkedhash.o: linkedhash.c linkedhash.h
	gcc -c -g -Wall linkedhash.c

clean:
	rm lex.yy.c
	rm *.o
	rm program
