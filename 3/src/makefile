sttc: sttc.o y.tab.o linkDicionario.o linkTexto.o linkedhash.o html.o htmlDic.o linkHtml.o
	@gcc -o sttc sttc.o y.tab.o linkDicionario.o linkTexto.o linkedhash.o html.o htmlDic.o linkHtml.o -ll
	@make clean
	@mkdir -p ../html/ > /dev/null 2>&1
	@cp style.css ../html > /dev/null 2>&1
	@mv sttc ../ > /dev/null 2>&1

sttc.o: sttc.c linkTexto.o
	@gcc -c sttc.c 

linkTexto.o: lexTexto.c y.tab.h
	@gcc -c lex.texto.c -o linkTexto.o

lexTexto.c: texto.l
	@echo "\033[0;31mBuilding binary...\033[0m"
	@flex -l -P texto texto.l > /dev/null 2>&1

y.tab.o: y.tab.c
	@gcc -c y.tab.c

linkDicionario.o: lex.yy.c y.tab.h 
	@gcc -c lex.yy.c -o linkDicionario.o

lex.yy.o: lex.yy.c
	@gcc -c lex.yy.c

y.tab.c y.tab.h: dicionario.y
	@yacc -d dicionario.y

lex.yy.c: dicionario.l y.tab.h
	@flex dicionario.l

linkedhash.o: linkedhash.c linkedhash.h
	@gcc -c -g -Wall linkedhash.c

html.o: html.c html.h
	@gcc -c -g -Wall html.c

htmlDic.o: htmlDic.c htmlDic.h
	@gcc -c -g -Wall htmlDic.c

lexHtml.c: dicHtml.l
	@flex -l -P html dicHtml.l > /dev/null 2>&1

linkHtml.o: lexHtml.c y.tab.h
	@gcc -c lex.html.c -o linkHtml.o

clean:
	@rm -f lex.yy.c lex.texto.c y.tab.c y.tab.h > /dev/null 2>&1
	@rm -rf ../html > /dev/null 2>&1
	@rm -f *.o > /dev/null 2>&1
	@rm -f ../sttc > /dev/null 2>&1
