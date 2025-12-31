CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -g
LDFLAGS = -lgmp -lgmpxx

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

# Find all header files
PROBLEM_HDRS = $(wildcard $(PROB_DIR)/*.h)
UTIL_HDRS = $(wildcard $(SRC_DIR)/utils/*.h)

ALL_SRCS = $(MAIN_SRC) $(PROBLEM_SRCS) $(UTIL_SRCS)
ALL_HDRS = $(PROBLEM_HDRS) $(UTIL_HDRS)
TEST_SRCS = $(TEST_SRC) $(UTIL_SRCS)

# Default problem to run
PROB ?= 1

.PHONY: all clean run test rebuild

all: $(TARGET)

rebuild:
	rm -f $(TARGET)
	$(MAKE) all

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(ALL_SRCS) $(ALL_HDRS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(ALL_SRCS) -o $(TARGET) $(LDFLAGS)

$(TEST_TARGET): $(TEST_SRCS) $(UTIL_HDRS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_SRCS) -o $(TEST_TARGET) $(LDFLAGS)

run: $(TARGET)
	@./$(TARGET) $(PROB)

test: $(TEST_TARGET)
	@./$(TEST_TARGET)

clean:
	rm -rf $(BUILD_DIR)
