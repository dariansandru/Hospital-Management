#include "Stack.h"

Stack::Stack() { size = 0; }

void Stack::push(const std::string& elem) {
    if (this->isFull()) return;

    size++;
    elements[size] = elem;
}

std::string Stack::pop() {
    if (this->isEmpty()) return nullptr;
    std::string elem = elements[size];
    size--;

    return elem;
}

std::string Stack::peek() {
    return elements[size];
}

bool Stack::isFull() const {
    if (size == 10) return true;
    return false;
}

bool Stack::isEmpty() const {
    if (size == 0) return true;
    return false;
}