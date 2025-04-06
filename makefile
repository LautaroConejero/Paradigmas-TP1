CXX = g++
CXXFLAGS = -std=c++17 -Wall
SRC = Ej_3/Persona_Factory.cpp Ej_3/Creacion_terminal.cpp Ej_4/combate.cpp main.cpp
EXEC = main.exe

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXEC)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXEC)

clean:
	rm -f $(EXEC)
