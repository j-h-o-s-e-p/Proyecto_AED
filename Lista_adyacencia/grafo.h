#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>

struct Nodo {
    int destino;
    Nodo* siguiente;
    
    Nodo(int dest) : destino(dest), siguiente(nullptr) {}
};

class Grafo {
private:
    Nodo** listaAdyacencia;  // Array de punteros a nodos
    int numVertices;         // Número de vértices
    bool esDirigido;         // Indica si el grafo es dirigido o no

public:
    Grafo(int vertices, bool dirigido = false);
    
    ~Grafo();
    
    // Función para agregar una arista
    void agregarArista(int origen, int destino);
    
    // Función para imprimir el grafo
    void imprimir() const;
    
    // Función para liberar la memoria manualmente
    void liberarMemoria();

    // Función para buscar si existe una arista
    bool existeArista(int origen, int destino) const;
    
    // Getters
    int obtenerNumVertices() const;
    bool esDirigidoGrafo() const;
    
private:
    // Función para agregar un nodo a una lista
    void agregarNodo(int indice, int destino);
    
    // Función para liberar una lista específica
    void liberarLista(Nodo* cabeza);
};

#endif
