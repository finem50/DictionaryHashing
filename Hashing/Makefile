#variable for the compiler
CC = g++
#Tell the compiler to use c++ 11 standard
CFLAGS = -std=c++11 -c

#Run "make all" in the command line to compile all programs
all: avlmain

#AVL Tree Dictionary program
avlmain: avlmain.o
	$(CC) avlmain.o -o avlmain

avlmain.o:
	$(CC) $(CFLAGS) avlmain.cpp

#Hash Dictionary program
#

clean:
	rm *.o

refresh: clean all
