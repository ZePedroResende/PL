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


quatro: quatro.l Graph.o
	@mkdir -p ../../build
	@flex --noyywrap quatro.l
	$(CXX) lex.yy.cc Graph.o -o quatro $(CFLAGS)
	@rm lex.yy.cc Graph.o
	@mv quatro ../../build

Graph.o:
	$(CXX) -c Graph.cpp -std=c++11

clean:
	@rm -rf lex.yy.cc *.o *.ps *.dot 2>/dev/null || true
