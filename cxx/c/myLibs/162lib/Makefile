lib162lib.a: 162lib.o
	ar -vr lib162lib.a 162lib.o
	rm 162lib.o

162lib.o: 162lib.h 162lib.c
	gcc -c -Wall -pedantic 162lib.c

install: lib162lib.a
	mv lib162lib.a /usr/local/lib
	cp 162lib.h /usr/local/include
