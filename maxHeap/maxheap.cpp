#include "maxheap.h"
#include <iostream>

// Métodos privados
void MaxHeap::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void MaxHeap::resize(int newCapacity) {
    int* newArr = new int[newCapacity];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}

int MaxHeap::parent(int i) {
    return (i - 1) / 2;
}

int MaxHeap::left(int i) {
    return 2 * i + 1;
}

int MaxHeap::right(int i) {
    return 2 * i + 2;
}

void MaxHeap::heapifyUp(int index) {
    while (index > 0 && arr[parent(index)] < arr[index]) {
        swap(arr[parent(index)], arr[index]);
        index = parent(index);
    }
}

void MaxHeap::heapifyDown(int index) {
    int largest = index;
    int l = left(index);
    int r = right(index);

    if (l < size && arr[l] > arr[largest])
        largest = l;

    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != index) {
        swap(arr[index], arr[largest]);
        heapifyDown(largest);
    }
}

// Constructores
MaxHeap::MaxHeap(int cap) : capacity(cap), size(0) {
    arr = new int[capacity];
}

MaxHeap::MaxHeap(int* array, int n) : capacity(n), size(n) {
    arr = new int[capacity];
    for (int i = 0; i < n; i++) {
        arr[i] = array[i];
    }
    for (int i = n/2 - 1; i >= 0; i--) {
        heapifyDown(i);
    }
}

// Regla de tres
MaxHeap::MaxHeap(const MaxHeap& other) : 
    capacity(other.capacity), size(other.size) {
    arr = new int[capacity];
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}

MaxHeap& MaxHeap::operator=(const MaxHeap& other) {
    if (this != &other) {
        delete[] arr;
        capacity = other.capacity;
        size = other.size;
        arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

MaxHeap::~MaxHeap() {
    delete[] arr;
}

// Semántica de movimiento
MaxHeap::MaxHeap(MaxHeap&& other) noexcept : 
    arr(other.arr), size(other.size), capacity(other.capacity) {
    other.arr = nullptr;
    other.size = other.capacity = 0;
}

MaxHeap& MaxHeap::operator=(MaxHeap&& other) noexcept {
    if (this != &other) {
        delete[] arr;
        arr = other.arr;
        size = other.size;
        capacity = other.capacity;
        other.arr = nullptr;
        other.size = other.capacity = 0;
    }
    return *this;
}

// Operaciones básicas
void MaxHeap::insert(int value) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    arr[size] = value;
    size++;
    heapifyUp(size - 1);
}

int MaxHeap::getMax() {
    if (isEmpty()) {
        throw std::runtime_error("Heap is empty");
    }
    return arr[0];
}

int MaxHeap::extractMax() {
    if (isEmpty()) {
        throw std::runtime_error("Heap is empty");
    }
    int max = arr[0];
    arr[0] = arr[size - 1];
    size--;
    if (size > 0) {
        heapifyDown(0);
    }
    return max;
}

bool MaxHeap::isEmpty() const {
    return size == 0;
}

// Utilidades
void MaxHeap::print() const {
    if (isEmpty()) {
        std::cout << "Heap: []" << std::endl;
        return;
    }
    std::cout << "Heap: [";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

// Getters
int MaxHeap::getSize() const {
    return size;
}

int MaxHeap::getCapacity() const {
    return capacity;
}
