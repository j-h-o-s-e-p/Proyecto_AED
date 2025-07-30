#pragma once
#include <cstdlib>
#include <stdexcept>

template<typename T>
class Array {
private:
    T* data;
    size_t size;
    size_t capacity;
    
    void expand() {
        capacity = capacity == 0 ? 1 : capacity * 2;
        T* newData = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    Array() : data(nullptr), size(0), capacity(0) {}
    
    ~Array() {
        delete[] data;
    }
    
    void push_back(const T& element) {
        if (size >= capacity) {
            expand();
        }
        data[size++] = element;
    }
    
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    
    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    
    void resize(size_t new_size) {
        if (new_size > capacity) {
            capacity = new_size;
            T* newData = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        size = new_size;
    }
    
    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
    
    // Iteradores básicos
    T* begin() { return data; }
    T* end() { return data + size; }
    const T* begin() const { return data; }
    const T* end() const { return data + size; }
};
