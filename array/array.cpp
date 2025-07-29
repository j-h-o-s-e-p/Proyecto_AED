#include "array.h"

// Para manejo de errores básico
extern "C" {
#include <stdio.h>
#include <stdlib.h>
}

// Constructor
Array::Array(unsigned int initial_capacity) : size(0), capacity(initial_capacity) {
    if (initial_capacity == 0) {
        initial_capacity = 1; // Evitar capacidad 0
    }
    data = new Node*[initial_capacity];
    capacity = initial_capacity;
    
    // Inicializar todos los punteros a nullptr
    for (unsigned int i = 0; i < capacity; i++) {
        data[i] = nullptr;
    }
}

// Destructor
Array::~Array() {
    delete[] data;
}

// Constructor de copia
Array::Array(const Array& other) : size(other.size), capacity(other.capacity) {
    data = new Node*[capacity];
    for (unsigned i = 0; i < size; i++) data[i] = other.data[i]; // Solo copiar lo necesario
}

// Operador de asignación
Array& Array::operator=(const Array& other) {
    if (this == &other) return *this;
    
    delete[] data;
    size = other.size;
    capacity = other.capacity;
    data = new Node*[capacity];
    for (unsigned i = 0; i < size; i++) data[i] = other.data[i]; // Solo copia lo necesario
    return *this;
}

// Añadir puntero a Node al final
void Array::push_back(Node* value) {
    // Si el array está lleno, redimensionar
    if (size >= capacity) {
        resize(capacity * 2); // Duplicar capacidad
    }
    data[size] = value;
    size++;
}

// Acceder a puntero Node solo para lectura
Node* Array::at(unsigned int index) const {
    if (index >= size) {
        ARRAY_ERROR("Index out of range");
    }
    return data[index];
}
// Acceder a referencia del puntero Node para modificar
Node*& Array::at(unsigned int index) {
    if (index >= size) {
        ARRAY_ERROR("Index out of range");
    }
    return data[index];
}

// Redimensionar el array
void Array::resize(unsigned int new_capacity) {
    if (new_capacity < size) new_capacity = size;
    
    Node** new_data = new Node*[new_capacity];
    // Copiar elementos existentes
    for (unsigned i = 0; i < size; i++) new_data[i] = data[i];
    
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}
