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


dois: dois.l TextAnalizer.o
	@mkdir -p ../../build
	@flex --noyywrap dois.l
	$(CXX) lex.yy.cc TextAnalizer.o -o dois $(CFLAGS)
	@rm lex.yy.cc TextAnalizer.o
	@mv dois ../../build

dois2: dois.2.l TextAnalizer.o
	@mkdir -p ../../build
	@flex --noyywrap dois.2.l
	$(CXX) lex.yy.cc TextAnalizer.o -o dois2 $(CFLAGS)
	@rm lex.yy.cc TextAnalizer.o


TextAnalizer.o:
	$(CXX) -c TextAnalizer.cpp -std=c++11

clean:
	@rm -rf um lex.yy.cc *.o 2>/dev/null || true


