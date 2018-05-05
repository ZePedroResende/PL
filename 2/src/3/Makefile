CFLAGS = -Wall -Wno-deprecated-register -std=c++11

ifeq ($(OS),Windows_NT)
	@echo "Cant't compile here, sorry :'("
	exit
endif

detected_OS := $(shell sh -c 'uname -s 2>/dev/null || echo not')
ifeq ($(detected_OS),Darwin)
	CFLAGS += -ll
else
	CFLAGS += -lfl
endif


ccc: ccc.l Authors.o Registo.o
	@flex --noyywrap ccc.l
	$(CXX) lex.yy.cc Authors.o Registo.o -o ccc $(CFLAGS)
	@rm lex.yy.cc Authors.o Registo.o
	@mv ccc ../build

Authors.o:
	$(CXX) -c Authors.cpp -std=c++11

Registo.o:
	$(CXX) -c Registo.cpp -std=c++11

clean:
	@rm -rf ccc lex.yy.cc *.o 2>/dev/null || true


