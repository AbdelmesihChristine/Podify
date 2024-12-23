#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "defs.h"

/**
 * @brief A templated array class with operator overloading demonstrating 
 *        how we can add and remove elements (operator+=, operator-=) 
 *        and access elements (operator[]).
 * 
 * This class shows:
 *   - **Templates** (T can be any type).
 *   - **Operator Overloading** for +=, -=, and [].
 */
template <typename T>
class Array {
public:
    Array();
    ~Array();

    // Operator+= to add an item to the Array
    Array& operator+=(const T& item);

    // Operator-= to remove an item from the Array
    Array& operator-=(const T& item);

    // Overloaded index operator (read-write)
    T& operator[](int index);

    // Overloaded index operator (read-only)
    const T& operator[](int index) const;

    int getSize() const;
    void clear();
    bool isFull() const;

private:
    int numElements;
    T elements[MAX_ARR];
};

template <typename T>
Array<T>::Array() : numElements(0) {}

template <typename T>
Array<T>::~Array() {
    // No dynamic memory used here.
}

template <typename T>
Array<T>& Array<T>::operator+=(const T& item) {
    if (numElements >= MAX_ARR) {
        std::cerr << "Array is full. Cannot add more items." << std::endl;
        return *this;
    }
    elements[numElements++] = item;
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator-=(const T& item) {
    int index = 0;
    while (index < numElements) {
        if (elements[index] == item) {
            break;
        }
        ++index;
    }
    if (index == numElements) return *this; // item not found
    --numElements;
    for (; index < numElements; ++index) {
        elements[index] = elements[index + 1];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= numElements) {
        std::cerr << "Array index out of bounds" << std::endl;
        exit(1);
    }
    return elements[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {
    if (index < 0 || index >= numElements) {
        std::cerr << "Array index out of bounds" << std::endl;
        exit(1);
    }
    return elements[index];
}

template <typename T>
int Array<T>::getSize() const {
    return numElements;
}

template <typename T>
void Array<T>::clear() {
    numElements = 0;
}

template <typename T>
bool Array<T>::isFull() const {
    return numElements == MAX_ARR;
}

#endif // ARRAY_H