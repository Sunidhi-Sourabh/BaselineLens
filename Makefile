# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I.

# Source files
SRC = main.cpp scanner.cpp json_loader.cpp validator.cpp fallback.cpp
OBJ = $(SRC:.cpp=.o)

# Output binary
TARGET = baselinelens

# Default build
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJ) $(TARGET)
