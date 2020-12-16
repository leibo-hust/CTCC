SOURCE_FILE = $(wildcard src/*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SOURCE_FILE))
CC = g++
CFLAGS = -c -Wall -Wno-sign-compare
LFLAGS = -Wall

all: main
main: $(OBJS)
	$(CC) $(LFLAGS) $^ -o $@
%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@
src/main.o: src/main.cpp src/functions.h src/Insert.h
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean  
clean:
	rm -rf $(OBJS) main