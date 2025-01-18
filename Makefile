# Compilers and flags
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
TESTS_DIR = tests
TESTS_BUILD_DIR = $(BUILD_DIR)/tests

# Files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
TARGET = $(BUILD_DIR)/libdatastructures.a
TEST_SRCS = $(wildcard $(TESTS_DIR)/*.c)
TEST_OBJS = $(TEST_SRCS:$(TESTS_DIR)/%.c=$(TESTS_BUILD_DIR)/%.o)
TEST_BINS = $(TEST_SRCS:$(TESTS_DIR)/%.c=$(TESTS_BUILD_DIR)/%)

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	ar rcs $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TESTS_BUILD_DIR)/%.o: $(TESTS_DIR)/%.c
	@mkdir -p $(TESTS_BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

check: $(TARGET) $(TEST_BINS)
	@for test in $(TEST_BINS); do \
		$$test; \
	done

$(TESTS_BUILD_DIR)/%: $(TESTS_BUILD_DIR)/%.o $(TARGET)
	$(CC) $(CFLAGS) $< -L$(BUILD_DIR) -ldatastructures -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all check clean
