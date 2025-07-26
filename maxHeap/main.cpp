#include "maxheap.h"
#include <iostream>

int main() {
    // Ejemplo con constructor de array
    int datos[] = {10, 20, 15, 40, 50, 100, 25, 45};
    MaxHeap heap(datos, 8);
    
    std::cout << "Heap construido desde array:" << std::endl;
    heap.print();
    
    // Insertar elementos adicionales
    heap.insert(200);
    heap.insert(5);
    
    std::cout << "\nDespués de insertar 200 y 5:" << std::endl;
    heap.print();
    
    // Probar getMax y extractMax
    try {
        std::cout << "\nMáximo actual: " << heap.getMax() << std::endl;
        std::cout << "Extraído máximo: " << heap.extractMax() << std::endl;
        std::cout << "Nuevo máximo: " << heap.getMax() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    // Probar movimiento
    MaxHeap heap2 = std::move(heap);
    std::cout << "\nDespués de mover:" << std::endl;
    std::cout << "Heap original (debería estar vacío): ";
    heap.print();
    std::cout << "Nuevo heap: ";
    heap2.print();
    
    // Probar vacío
    MaxHeap heapVacio;
    std::cout << "\nProbando heap vacío:" << std::endl;
    try {
        heapVacio.getMax();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error esperado: " << e.what() << std::endl;
    }
    
    return 0;
}
