#include "grafo.h"

int main() {
    // Ejemplo Grafo no dirigido
    std::cout << "EJEMPLO: GRAFO NO DIRIGIDO" << std::endl;
    Grafo grafoNoDirigido(5, false);
    
    // Agregamos aristas
    grafoNoDirigido.agregarArista(0, 1);
    grafoNoDirigido.agregarArista(0, 4);
    grafoNoDirigido.agregarArista(1, 2);
    grafoNoDirigido.agregarArista(1, 3);
    grafoNoDirigido.agregarArista(1, 4);
    grafoNoDirigido.agregarArista(2, 3);
    grafoNoDirigido.agregarArista(3, 4);
    
    // Imprimir el grafo
    grafoNoDirigido.imprimir();
    
    // Ejemplo Grafo dirigido
    std::cout << "EJEMPLO: GRAFO DIRIGIDO" << std::endl;
    Grafo grafoDirigido(4, true);
    
    // Agregar aristas dirigidas
    grafoDirigido.agregarArista(0, 1);
    grafoDirigido.agregarArista(0, 2);
    grafoDirigido.agregarArista(1, 2);
    grafoDirigido.agregarArista(2, 0);
    grafoDirigido.agregarArista(2, 3);
    grafoDirigido.agregarArista(3, 3); 
    
    // Imprimir el grafo dirigido
    grafoDirigido.imprimir();
    
    // Mostramos información adicional
    std::cout << "Información del grafo no dirigido:" << std::endl;
    std::cout << "Número de vértices: " << grafoNoDirigido.obtenerNumVertices() << std::endl;
    std::cout << "¿Es dirigido?: " << (grafoNoDirigido.esDirigidoGrafo() ? "Sí" : "No") << std::endl;
    
    std::cout << "\nInformación del grafo dirigido:" << std::endl;
    std::cout << "Número de vértices: " << grafoDirigido.obtenerNumVertices() << std::endl;
    std::cout << "¿Es dirigido?: " << (grafoDirigido.esDirigidoGrafo() ? "Sí" : "No") << std::endl;
    
    // Ejemplo de búsqueda de aristas
    std::cout << "\n=== PRUEBA DE BÚSQUEDA DE ARISTAS ===" << std::endl;
    std::cout << "¿Existe arista 0->1 en grafo no dirigido?: " << (grafoNoDirigido.existeArista(0, 1) ? "Sí" : "No") << std::endl;
    std::cout << "¿Existe arista 1->0 en grafo no dirigido?: " << (grafoNoDirigido.existeArista(1, 0) ? "Sí" : "No") << std::endl;
    std::cout << "¿Existe arista 0->3 en grafo no dirigido?: " << (grafoNoDirigido.existeArista(0, 3) ? "Sí" : "No") << std::endl;
    
    std::cout << "¿Existe arista 0->1 en grafo dirigido?: " << (grafoDirigido.existeArista(0, 1) ? "Sí" : "No") << std::endl;
    std::cout << "¿Existe arista 1->0 en grafo dirigido?: " << (grafoDirigido.existeArista(1, 0) ? "Sí" : "No") << std::endl;
    std::cout << "¿Existe arista 3->3 en grafo dirigido?: " << (grafoDirigido.existeArista(3, 3) ? "Sí" : "No") << std::endl;
    
    // Ejemplo de manejo de errores
    std::cout << "\nPRUEBA DE MANEJO DE ERRORES" << std::endl;
    grafoNoDirigido.agregarArista(10, 1); 
    grafoNoDirigido.agregarArista(1, -1);
    
    /* La memoria se libera automáticamente al salir del scope
    gracias al destructor, pero también se puede hacer manualmente:
    grafoNoDirigido.liberarMemoria();*/
    
    return 0;
}
