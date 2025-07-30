#pragma once
#include "Array.h"

template<typename T>
struct Less {
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

template<typename T>
struct Greater {
    bool operator()(const T& a, const T& b) const {
        return a > b;
    }
};

template<typename T, typename Compare = Less<T>>
class PriorityQueue {
private:
    Array<T> heap;
    Compare comp;
    
    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }
    
    size_t parent(size_t i) const { 
        return (i - 1) / 2; 
    }
    
    size_t left(size_t i) const { 
        return 2 * i + 1; 
    }
    
    size_t right(size_t i) const { 
        return 2 * i + 2; 
    }
    
    void heapifyUp(size_t index) {
        while (index > 0 && comp(heap[index], heap[parent(index)])) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }
    
    void heapifyDown(size_t index) {
        size_t best = index;
        size_t l = left(index);
        size_t r = right(index);
        
        if (l < heap.getSize() && comp(heap[l], heap[best])) {
            best = l;
        }
        
        if (r < heap.getSize() && comp(heap[r], heap[best])) {
            best = r;
        }
        
        if (best != index) {
            swap(heap[index], heap[best]);
            heapifyDown(best);
        }
    }
    
public:
    // Constructor por defecto
    PriorityQueue() = default;
    
    // Constructor con comparador personalizado
    explicit PriorityQueue(const Compare& c) : comp(c) {}
    
    // Constructor de copia
    PriorityQueue(const PriorityQueue& other) : heap(other.heap), comp(other.comp) {}
    
    // Operador de asignación
    PriorityQueue& operator=(const PriorityQueue& other) {
        if (this != &other) {
            heap = other.heap;
            comp = other.comp;
        }
        return *this;
    }
    
    // Insertar elemento
    void push(const T& element) {
        heap.push_back(element);
        heapifyUp(heap.getSize() - 1);
    }
    
    // Obtener elemento con mayor prioridad
    const T& top() const {
        if (heap.getSize() == 0) {
            throw std::out_of_range("PriorityQueue is empty");
        }
        return heap[0];
    }
    
    // Eliminar elemento con mayor prioridad
    void pop() {
        if (heap.getSize() == 0) {
            throw std::out_of_range("PriorityQueue is empty");
        }
        
        // Mover último elemento al inicio
        heap[0] = heap[heap.getSize() - 1];
        
        // Reducir tamaño manualmente (tu Array necesita esto)
        heap.resize(heap.getSize() - 1);
        
        // Restaurar propiedad de heap
        if (heap.getSize() > 0) {
            heapifyDown(0);
        }
    }
    
    // Verificar si está vacía
    bool empty() const {
        return heap.getSize() == 0;
    }
    
    // Obtener tamaño
    size_t size() const {
        return heap.getSize();
    }
    
    // Limpiar cola
    void clear() {
        heap.resize(0);
    }
    
};
