/*
 * File: charstack.cpp
 * -------------------
 * This file implements the CharStack class.
 */

#include "charstack.h"
#include "error.h"
using namespace std;

/*
 * Implementation notes: constructor and destructor
 * ------------------------------------------------
 * The constructor allocates the array storage for the stack elements and
 * initializes the fields of the object. The destructor frees any heap
 * memory allocated by the class, which is just the array of elements.
 */

CharStack::CharStack() {
    capacity = INITIAL_CAPACITY;
    array = new char[capacity];
    count = 0;
}

/*
 * Implementation notes: ~Charstack
 * --------------------------------
 * The destructor frees any heap memory allocated by the class, which
 * is just the dynamic array of elements.
 */

CharStack::~CharStack() {
    delete[] array;
}

/*
 * Implementation notes: size, isEmpty, clear
 * ------------------------------------------
 * These methods are each a single line and need no detailed documentation.
 */

int CharStack::size() {
    return count;
}

bool CharStack::isEmpty() {
    return count == 0;
}

void CharStack::clear() {
    count = 0;
}

/*
 * Implementation notes: push
 * --------------------------
 * This function first checks to see whether there is enough room for
 * the character and then expands the array storage if necessary.
 */

void CharStack::push(char ch) {
    if (count == capacity) expandCapacity();
    array[count++] = ch;
}

/*
 * Implementationnotes: pop, peek
 * ------------------------------
 * These functions check for an empty stack and report an error if
 * there is no top element.
 */

char CharStack::pop() {
    if (isEmpty()) error("pop: Attempting to pop an empty stack");
    return array[--count];
}

char CharStack::peek() {
    if (isEmpty()) error("peek: Attempting to peek an empty stack");
    return array[count - 1];
}