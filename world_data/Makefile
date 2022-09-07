.POSIX:
all: clean build

build: wdata.o
	${CXX} wdata.o -o wdata

wdata.o:
	${CXX} -c wdata.cpp

clean:
	rm -f wdata.o
