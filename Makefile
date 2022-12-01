##
 # @file Makefile
 # @author Vance Brenderabrandis + Jacqueline
 # @date 2022-12-1
 # @brief Makefile for Deque implementation program
 # 
 # Makefile with instructions to compile object code from driver and Deque sourcecode and link them together
##


CC = g++ # Compiler is g++
TARGET = deque # Target executable name
CFLAGS = -c -Wall -Wextra # Compile with all warnings and extra warnings

default: all # Typing "make" into console does default action, which is all

all:	$(TARGET)

$(TARGET):	deque.o main.o # Links object files together into executable
	$(CC) -Wall -Wextra -o $(TARGET) deque.o main.o

deque.o:	deque.cpp deque.h # Compiles Deque source code into object code
	$(CC) $(CFLAGS) deque.cpp

main.o:		main.cpp deque.h # compiles main driver into object code
	$(CC) $(CFLAGS) main.cpp

clean:
	$(RM) $(TARGET) *.o *~
