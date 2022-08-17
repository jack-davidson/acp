.POSIX:
all: clean build

build: helloworld.o
	${CXX} helloworld.o -o helloworld

helloworld.o:
	${CXX} -c helloworld.cpp

clean:
	rm -f helloworld.o
