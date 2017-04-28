# Compiler
CC = g++

# Debugging
DEBUG = -g

# Compiler Flags
CFLAGS = -c -Wall $(DEBUG)

# Target
TARGET = HEAP

$(TARGET): main.o
	$(CC) main.o -o HEAP

main.o: main.cpp heap.h
	$(CC) $(CFLAGS) main.cpp

clean:
	rm *.o *~ $(TARGET)
