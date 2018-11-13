#variable for the compiler
CC = g++
#Tell the compiler to use c++ 11 standard
CFLAGS = -std=c++11 -c

#Run "make all" in the command line to compile all programs
all: hashmain

#AVL Tree Dictionary program
avlmain: hashmain.o
	$(CC) hashmain.o -o hashmain

avlmain.o:
	$(CC) $(CFLAGS) hashmain.cpp

#Hash Dictionary program
#

clean:
	rm *.o

refresh: clean all
