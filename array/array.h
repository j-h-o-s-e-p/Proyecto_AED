#ifndef ARRAY_H
#define ARRAY_H
#define ARRAY_ERROR(msg) do { fprintf(stderr, "Array Error: %s\n", msg); exit(EXIT_FAILURE); } while(0)

struct Node; 

class Array {
private:
    Node** data;  
    unsigned int size;
    unsigned int capacity;

public:
    Array(unsigned int initial_capacity = 10);
    ~Array();
    Array(const Array& other); 
    Array& operator=(const Array& other); 

    void push_back(Node* value);
    Node* at(unsigned int index) const;
    Node*& at(unsigned int index);
    void resize(unsigned int new_capacity);

    Node*& unsafe_at(unsigned int index) { return data[index]; }

    unsigned int get_size() const { return size; }
    unsigned int get_capacity() const { return capacity; }
};

#endif // ARRAY_H
