#include "grafo.h"

Grafo::Grafo(int vertices, bool dirigido) : numVertices(vertices), esDirigido(dirigido) {
    // Crea un array de punteros a nodos, inicializados en nullptr
    listaAdyacencia = new Nodo*[numVertices];
    for (int i = 0; i < numVertices; i++) {
        listaAdyacencia[i] = nullptr;
    }
}

Grafo::~Grafo() {
    liberarMemoria();
}

// Función para agregar una arista
void Grafo::agregarArista(int origen, int destino) {
    // Verificar que los índices sean válidos
    if (origen < 0 || origen >= numVertices || destino < 0 || destino >= numVertices) {
        std::cout << "Error: Índices de vértices inválidos" << std::endl;
        return;
    }
    
    // Agregar arista desde origen hacia destino
    agregarNodo(origen, destino);
    
    // Si el grafo no es dirigido, agrega también la arista inversa
    if (!esDirigido) {
        agregarNodo(destino, origen);
    }
}

// Función para agregar un nodo a una lista específica
void Grafo::agregarNodo(int indice, int destino) {
    // Creamos nuevo nodo
    Nodo* nuevoNodo = new Nodo(destino);
    
    // Si la lista está vacía, el nuevo nodo se convierte en la cabeza
    if (listaAdyacencia[indice] == nullptr) {
        listaAdyacencia[indice] = nuevoNodo;
    } else {
        // Insertar al inicio de la lista para O(1)
        nuevoNodo->siguiente = listaAdyacencia[indice];
        listaAdyacencia[indice] = nuevoNodo;
    }
}

// Función para imprimir el grafo
void Grafo::imprimir() const {
    std::cout << "\n=== GRAFO " << (esDirigido ? "DIRIGIDO" : "NO DIRIGIDO") << " ===" << std::endl;
    std::cout << "Número de vértices: " << numVertices << std::endl;
    std::cout << "\nLista de Adyacencia:" << std::endl;
    
    for (int i = 0; i < numVertices; i++) {
        std::cout << "Vértice " << i << ": ";
        
        Nodo* actual = listaAdyacencia[i];
        if (actual == nullptr) {
            std::cout << "vacío";
        } else {
            while (actual != nullptr) {
                std::cout << actual->destino;
                if (actual->siguiente != nullptr) {
                    std::cout << " -> ";
                }
                actual = actual->siguiente;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "========================\n" << std::endl;
}

// Función para liberar la memoria manualmente
void Grafo::liberarMemoria() {
    if (listaAdyacencia != nullptr) {
        // Libera cada lista de adyacencia
        for (int i = 0; i < numVertices; i++) {
            liberarLista(listaAdyacencia[i]);
        }
        
        // Libera el array de punteros
        delete[] listaAdyacencia;
        listaAdyacencia = nullptr;
    }
}

// Función para buscar si existe una arista entre dos nodos
bool Grafo::existeArista(int origen, int destino) const {
    // Verifica que los índices sean válidos
    if (origen < 0 || origen >= numVertices || destino < 0 || destino >= numVertices) {
        return false;
    }
    
    // Recorre la lista de adyacencia del nodo origen
    Nodo* actual = listaAdyacencia[origen];
    while (actual != nullptr) {
        if (actual->destino == destino) {
            return true;
        }
        actual = actual->siguiente;
    }
    
    return false;
}

// Función para liberar una lista específica
void Grafo::liberarLista(Nodo* cabeza) {
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

// Getters
int Grafo::obtenerNumVertices() const {
    return numVertices;
}

bool Grafo::esDirigidoGrafo() const {
    return esDirigido;
}
