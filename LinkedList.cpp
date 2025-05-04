// LinkedList.cpp
// Xander David
// This file contains the implementation of the LinkedList class and its methods.

#include "LinkedList.h"
#include <iostream>
#include <utility>

std::ostream &operator<<(std::ostream &os, const std::pair<int, int> &p)
{
    os << "(" << p.first << ", " << p.second << ")"; // Output pair in (x, y) format
    return os;
}

template <typename T> // Template class for LinkedList
LinkedList<T>::LinkedList() : head(nullptr), size(0)
{
} // Constructor initializes head to nullptr and size to 0

template <typename T> // Destructor to free memory
LinkedList<T>::~LinkedList()
{
    Node *current = head; // Start from the head
    while (current)
    {
        Node *toDelete = current; // Node to delete
        current = current->next;  // Move to the next node
        delete toDelete;          // Delete the current node
    }
}

template <typename T> // Insert a value at the front of the list
void LinkedList<T>::insertFront(T val)
{
    Node *newNode = new Node(val); // Create a new node
    newNode->next = head;          // Point new node to the current head
    head = newNode;                // Update head to the new node
    size++;                        // Increment size
}

template <typename T> // Remove a value from the list
void LinkedList<T>::remove(T val)
{
    Node *current = head; // Start from the head
    Node *prev = nullptr; // Previous node pointer

    while (current)
    {
        if (current->data == val)
        {
            if (prev)
                prev->next = current->next; // Bypass the current node
            else
                head = current->next; // Update head if current is the head

            delete current; // Delete the current node
            size--;         // Decrement size
            return;
        }
        prev = current;          // Move prev to current
        current = current->next; // Move current to the next node
    }
}

template <typename T> // Check if the list contains a value
bool LinkedList<T>::contains(T val) const
{
    Node *current = head; // Start from the head
    while (current)
    {
        if (current->data == val)
            return true;
        current = current->next; // Move to the next node
    }
    return false;
}

template <typename T> // Print the list
void LinkedList<T>::print() const
{
    Node *current = head; // Start from the head
    while (current)
    {
        std::cout << current->data << " -> "; // Print current node data
        current = current->next;              // Move to the next node
    }
    std::cout << "null\n";
}

template <typename T> // Get the size of the list
int LinkedList<T>::getSize() const
{
    return size;
}

template <typename T>
void LinkedList<T>::resetIterator()
{
    iter = head;
}

template <typename T>
bool LinkedList<T>::hasNext() const
{
    return iter != nullptr;
}

template <typename T>
T LinkedList<T>::next()
{
    if (!iter)
        throw std::runtime_error("Iterator is null");
    T val = iter->data;
    iter = iter->next;
    return val;
}

// Explicit instantiation
template class LinkedList<int>;                 // Explicit instantiation for int
template class LinkedList<std::pair<int, int>>; // Explicit instantiation for std::pair<int, int>
