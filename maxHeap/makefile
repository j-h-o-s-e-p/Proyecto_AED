# Compilador y flags
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -g

# Nombres de los archivos
HEADERS = maxheap.h
SOURCES = maxheap.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = maxheap_program

# Regla principal (por defecto)
all: $(TARGET)

# Regla para compilar el programa principal
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar cada .cpp en .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f $(OBJECTS) $(TARGET)

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)

# Reglas phony (no producen archivos con ese nombre)
.PHONY: all clean run
