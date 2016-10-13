
# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS = -g -std=c++11

# the build target executable: hash testing
TARGET = a.out
SOURCE1 = BinaryTree

all: $(TARGET)


$(TARGET): main.o
	$(CC)  main.o  -o $(TARGET)

main.o: main.cpp $(SOURCE1).h $(SOURCE1).cpp
	$(CC) $(CFLAGS) -c -o main.o main.cpp

#$(SOURCE).o: $(SOURCE).cpp
#	$(CC) $(CFLAGS) $(SOURCE).cpp

clean:
	rm *o $(TARGET)

run:
	./$(TARGET)
