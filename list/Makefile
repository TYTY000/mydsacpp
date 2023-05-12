CC = g++
CFLAGS = -g -o $(TARGET_EXEC) -I. -O0
DEPS = listNode.h list.h
TARGET = list_test.cpp
TARGET_EXEC = list_test
.DELETE_ON_ERROR:
all: $(PROGRAMS)
	$(CC)  $(DEPS) $(TARGET) $(CFLAGS)



.PHONY: clean

clean:
	rm -f *.cpp.* *.o $(TARGET_EXEC)
