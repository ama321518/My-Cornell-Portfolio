CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Werror -O2

SRC_DIR := src
TEST_DIR := tests
BIN_DIR := bin
BUILD_DIR := build

APP := $(BIN_DIR)/demo
TEST_BIN := $(BIN_DIR)/tests

SRC := $(SRC_DIR)/BankAccount.cpp
OBJ := $(BUILD_DIR)/BankAccount.o

.PHONY: all clean test run

all: $(APP) $(TEST_BIN)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/%.h
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(APP): $(OBJ) $(SRC_DIR)/main.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/main.cpp $(OBJ) -o $@

$(TEST_BIN): $(OBJ) $(TEST_DIR)/test_bank_account.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_DIR)/test_bank_account.cpp $(OBJ) -o $@

test: $(TEST_BIN)
	$(TEST_BIN) | cat

run: $(APP)
	$(APP) | cat

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

