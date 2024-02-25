.PHONY:all clean

all:StrList

StrList:Main.o StrList.o
	gcc -Wall -g Main.o StrList.o -o StrList

Main.o:Main.c StrList.h	
	gcc -Wall -g -c Main.c -o Main.o

StrList.o:StrList.c	StrList.h
	gcc -Wall -g -c StrList.c -o StrList.o



clean:
	rm -f *.o *.a StrList
 