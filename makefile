CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = $(shell find Ej_1 Ej_2 Ej_3 -name "*.cpp") main.cpp
OBJ = $(patsubst %.cpp, %.o, $(SRC))
EXEC = main.exe

all: clean $(EXEC)
	valgrind --leak-check=full --track-origins=yes ./$(EXEC)


$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)