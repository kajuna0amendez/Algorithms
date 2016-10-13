
# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS = -g -c

# the build target executable: hash testing
TARGET = HashTable


all: $(TARGET)
	 

$(TARGET): main.o hash_table.o
	$(CC)  main.o hash_table.o  -o $(TARGET)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

hash_table.o: hash_table.cpp 
	$(CC) $(CFLAGS) hash_table.cpp

clean: 
	rm *o $(TARGET) 

run: 
	./$(TARGET)