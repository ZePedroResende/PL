CFLAGS = -Wall -Wno-deprecated-register

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


um: um.l WordCounter.o
	@flex --noyywrap um.l
	$(CXX) -std=c++11 lex.yy.cc WordCounter.o -o um $(CFLAGS)
	@rm lex.yy.cc
	@mv um ../build

WordCounter.o:
	$(CXX) -c WordCounter.cpp -std=c++11

clean:
	@rm -rf um lex.yy.cc *.o 2>/dev/null || true


