# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Target executable
TARGET = program

# Source files
SRC = Main.cpp Board.cpp Pawn.cpp King.cpp Queen.cpp Bishop.cpp Knight.cpp Tower.cpp Player.cpp Game.cpp

# Object files (replace .cpp with .o)
OBJ = $(SRC:.cpp=.o)

# Default rule
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)
