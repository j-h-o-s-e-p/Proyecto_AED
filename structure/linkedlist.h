#pragma once
#include <stdexcept>

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    size_t size;
    
public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    ~LinkedList() {
        clear();
    }
    
    // Constructor de copia
    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), size(0) {
        Node* current = other.head;
        while (current) {
            insert(current->data);
            current = current->next;
        }
    }
    
    // Operador de asignación
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current) {
                insert(current->data);
                current = current->next;
            }
        }
        return *this;
    }
    
    // Insertar al final
    void insert(const T& element) {
        Node* newNode = new Node(element);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    // Insertar al inicio
    void push_front(const T& element) {
        Node* newNode = new Node(element);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    
    void push_back(const T& element) {
        insert(element);
    }
    
    // Eliminar del inicio
    void pop_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
        size--;
    }
    
    // Eliminar elemento específico
    void remove(const T& element) {
        Node* prev = nullptr;
        Node* current = head;
        
        while (current) {
            if (current->data == element) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                
                if (current == tail) {
                    tail = prev;
                }
                
                delete current;
                size--;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    
    // Buscar elemento
    bool find(const T& element) const {
        Node* current = head;
        while (current) {
            if (current->data == element) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    // Acceso al primer elemento
    T& front() { 
        if (!head) throw std::runtime_error("List is empty");
        return head->data; 
    }
    
    const T& front() const { 
        if (!head) throw std::runtime_error("List is empty");
        return head->data; 
    }
    
    // Acceso al último elemento
    T& back() { 
        if (!tail) throw std::runtime_error("List is empty");
        return tail->data; 
    }
    
    const T& back() const { 
        if (!tail) throw std::runtime_error("List is empty");
        return tail->data; 
    }
    
    // Verificar si está vacía
    bool empty() const { 
        return size == 0; 
    }
    
    // Obtener tamaño
    size_t getSize() const { 
        return size; 
    }
    
    // Limpiar lista
    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        size = 0;
    }
    
    class Iterator {
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}
        
        // Pre-incremento
        Iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }
        
        // Post-incremento
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }
        
        // Operadores de comparación
        bool operator==(const Iterator& other) const {
            return current == other.current;
        }
        
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
        
        // Desreferencia
        T& operator*() { 
            if (!current) throw std::runtime_error("Iterator out of bounds");
            return current->data; 
        }
        
        // Acceso a miembro
        T* operator->() { 
            if (!current) throw std::runtime_error("Iterator out of bounds");
            return &(current->data); 
        }
    };
    
    // Iteradores const
    class ConstIterator {
        const Node* current;
    public:
        ConstIterator(const Node* node) : current(node) {}
        
        ConstIterator& operator++() {
            if (current) current = current->next;
            return *this;
        }
        
        ConstIterator operator++(int) {
            ConstIterator temp = *this;
            ++(*this);
            return temp;
        }
        
        bool operator==(const ConstIterator& other) const {
            return current == other.current;
        }
        
        bool operator!=(const ConstIterator& other) const {
            return current != other.current;
        }
        
        const T& operator*() const { 
            if (!current) throw std::runtime_error("Iterator out of bounds");
            return current->data; 
        }
        
        const T* operator->() const { 
            if (!current) throw std::runtime_error("Iterator out of bounds");
            return &(current->data); 
        }
    };
    
    // Métodos para obtener iteradores
    Iterator begin() { 
        return Iterator(head); 
    }
    
    Iterator end() { 
        return Iterator(nullptr); 
    }
    
    ConstIterator begin() const { 
        return ConstIterator(head); 
    }
    
    ConstIterator end() const { 
        return ConstIterator(nullptr); 
    }
    
};
