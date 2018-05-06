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


um: um.l WordCounter.o
	@mkdir -p ../../build
	@flex --noyywrap um.l
	$(CXX) lex.yy.cc WordCounter.o -o um $(CFLAGS)
	@rm lex.yy.cc WordCounter.o
	@mv um ../../build

WordCounter.o:
	$(CXX) -c WordCounter.cpp -std=c++11

clean:
	@rm -rf um lex.yy.cc *.o 2>/dev/null || true


