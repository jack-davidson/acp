.POSIX:
all: clean build

build: lex.o
	${CXX} lex.o -o lex

lex.o:
	${CXX} -c lex.cpp

clean:
	rm -f lex.o
