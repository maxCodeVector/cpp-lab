CC=g++ -std=c++11

SRC=utf8.c check_language.cpp
TARGET=main

debug:$(SRC)
	$(CC) -g -o $(TARGET) $(SRC)


TEST_SRC=test_data
TEST_SOURCE+=$(sort $(wildcard $(TEST_SRC)/*.txt))

test:$(TARGET)
	@$(foreach var, $(TEST_SOURCE),\
		echo $(var);\
		./$(TARGET) < $(var); \
		echo "";\
	)