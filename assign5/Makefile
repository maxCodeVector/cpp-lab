CC=g++ -std=c++11

SRC=utf8.c testUTF8string.cpp UTF8string.cpp
INCLUDE=utf8.h UTF8string.hpp
TARGET=main
OBJS=$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SRC)))

%.o: %.cpp
	$(CC) -c -g $< -o $@

debug:$(OBJS) $(INCLUDE)
	$(CC) -g -o $(TARGET) $(OBJS)

utf8.o:utf8.c
	$(CC) -c -g $< -o $@


TEST_SRC=test_data
TEST_SOURCE+=$(sort $(wildcard $(TEST_SRC)/*.txt))

test:$(TARGET)
	./$(TARGET) > rel.res
	diff exp.res rel.res