# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Directories
SRC_DIR = src
TARGET = slm

# Source files
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/InfiniteMonkey.cpp $(SRC_DIR)/Banana.cpp
OBJS = $(SRCS:.cpp=.o)

# Default build rule
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@



# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean run
