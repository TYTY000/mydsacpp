CC = g++
CFLAGS = -g -o $(EXEC) -I. -O0
DEPS = QuadList.cpp SkipList.cpp
EXEC = SkipList_test
TARGET = SkipList_test.cpp
.DELETE_ON_ERROR:	
all:
	$(CC) $(DEPS) $(TARGET) $(CFLAGS)



.PHONY: clean
	clean:
	rm -f *.cpp.* *.o $(EXEC)

