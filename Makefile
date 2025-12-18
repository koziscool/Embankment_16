CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -g

TARGET = build/euler
TEST_TARGET = build/test_bigint
SRC_DIR = src
PROB_DIR = problems
BUILD_DIR = build

# Find all source files
MAIN_SRC = $(SRC_DIR)/main.cpp
TEST_SRC = $(SRC_DIR)/test_bigint.cpp
PROBLEM_SRCS = $(wildcard $(PROB_DIR)/*.cpp)
UTIL_SRCS = $(wildcard $(SRC_DIR)/utils/*.cpp)

ALL_SRCS = $(MAIN_SRC) $(PROBLEM_SRCS) $(UTIL_SRCS)
TEST_SRCS = $(TEST_SRC) $(UTIL_SRCS)

# Default problem to run
PROB ?= 1

.PHONY: all clean run test

all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(ALL_SRCS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(ALL_SRCS) -o $(TARGET)

$(TEST_TARGET): $(TEST_SRCS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_SRCS) -o $(TEST_TARGET)

run: $(TARGET)
	@./$(TARGET) $(PROB)

test: $(TEST_TARGET)
	@./$(TEST_TARGET)

clean:
	rm -rf $(BUILD_DIR)
