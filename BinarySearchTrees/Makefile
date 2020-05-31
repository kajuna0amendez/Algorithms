
# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS = -g -std=c++11

TARGET = a.out
INC=-I/home/andres/Dropbox/Code/c++/BinaryTrees

# common sources
COMMON_SRC1 = BinarySearchTree
COMMON_SRC2 = ../BinaryTrees/BinaryTree

all: $(TARGET)


$(TARGET): main.o
	$(CC)   main.o  -o $(TARGET)

main.o: main.cpp $(COMMON_SRC1).h $(COMMON_SRC1).cpp $(COMMON_SRC2).h $(COMMON_SRC2).cpp
	$(CC) $(INC) $(CFLAGS) -c -o main.o main.cpp


clean:
	rm *o $(TARGET)

run:
	./$(TARGET)
