program: main.o linkedhash.o
	gcc -o program main.o linkedhash.o

main.o: main.c linkedhash.h
	gcc -c -g -Wall main.c

linkedhash.o: linkedhash.c linkedhash.h
	gcc -c -g -Wall linkedhash.c

clean:
	rm *.o
	rm program
