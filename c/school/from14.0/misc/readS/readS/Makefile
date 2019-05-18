libreadS.a: readS.o
	ar -vr libreadS.a readS.o 

readS.o: readS.h readS.c
	gcc -c -Wall -pedantic readS.c

main: main.c
	gcc -o main -Wall -pedantic main.c -lreadS 

install: libreadS.a
	cp libreadS.a /usr/local/lib
	cp readS.h /usr/local/include

clean: 
	rm /usr/local/lib/libTerzaB.a
	rm /usr/local/include/readS.h
