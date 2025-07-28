CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = grafo
OBJECTS = main.o grafo.o

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.cpp grafo.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Grafo.o: grafo.cpp grafo.h
	$(CXX) $(CXXFLAGS) -c grafo.cpp

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean
