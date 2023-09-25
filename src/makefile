.PHONY: clean

all: main.o ctest/test.o
	gcc -o ../bin/ctest main.o ctest/test.o

main.o: main.c 
	gcc -I ./ -c main.c

ctest/test.o: ctest/test.c ctest/test.h
	gcc -I ./ -o ctest/test.o -c ctest/test.c

clean:
	rm -rf ./a.out ./*.o ./ctest/*.o
