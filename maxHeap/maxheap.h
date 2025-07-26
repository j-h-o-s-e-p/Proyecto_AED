#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <stdexcept>

class MaxHeap {
private:
    int* arr;      // arreglo dinámico que contiene el heap
    int size;      // número de elementos actuales
    int capacity;  // capacidad máxima del arreglo

    void swap(int& a, int& b);
    void resize(int newCapacity);
    int parent(int i);
    int left(int i);
    int right(int i);
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    // Constructores
    MaxHeap(int cap = 10);
    MaxHeap(int* array, int n);
    
    // Regla de tres (constructor de copia, operador asignación, destructor)
    MaxHeap(const MaxHeap& other);
    MaxHeap& operator=(const MaxHeap& other);
    ~MaxHeap();
    
    // Semántica de movimiento
    MaxHeap(MaxHeap&& other) noexcept;
    MaxHeap& operator=(MaxHeap&& other) noexcept;
    
    // Operaciones básicas
    void insert(int value);
    int getMax();
    int extractMax();
    bool isEmpty() const;
    
    // Utilidades
    void print() const;
    
    // Getters
    int getSize() const;
    int getCapacity() const;
};

#endif
