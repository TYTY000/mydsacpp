CC = g++
CFLAGS = -g -o $(TARGET_EXEC) -I. -O0
DEPS = ../list/listNode.h ../list/list.h stack.h
TARGET = stack_test.cpp
TARGET_EXEC = stack_test
.DELETE_ON_ERROR:
all: $(PROGRAMS)
	$(CC)  $(DEPS) $(TARGET) $(CFLAGS)



.PHONY: clean

clean:
	rm -f *.gch $(TARGET_EXEC)
