// LinkedList.h
// Xander David
// This file contains the definition of the LinkedList class and its methods.

#pragma once // Include guard to prevent multiple inclusions

template <typename T> // Template class for LinkedList
class LinkedList {
private:
    struct Node {
        T data; // Data stored in the node
        Node* next; // Pointer to the next node
        Node(T val) : data(val), next(nullptr) {} // Constructor
    };

    Node* head; // Pointer to the head of the list
    int size; // Size of the list
    Node* iter; // Iterator pointer for traversal

public:
    LinkedList(); // Constructor
    ~LinkedList(); // Destructor
    void insertFront(T val); // Insert a value at the front
    void remove(T val); // Remove a value from the list
    bool contains(T val) const; // Check if the list contains a value
    void print() const; // Print the list
    int getSize() const; // Get the size of the list
    void resetIterator(); // Reset iteration to head
    bool hasNext() const; // Check if more nodes exist
    T next();             // Get next node value
};
