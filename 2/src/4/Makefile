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

v=quatro

$v: $v.l
	flex --noyywrap $v.l
	$(CXX) lex.yy.cc -o $v -lfl
	rm lex.yy.cc
clean:
	rm quatro

