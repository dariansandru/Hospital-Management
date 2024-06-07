// THIS CLASS IS NOT USED ANYWHERE

#pragma once

#include <string>

#ifndef HOSPITAL_STACK_H
#define HOSPITAL_STACK_H

class Stack {
public:
    Stack();
    void push(const std::string&);
    std::string pop();

    std::string peek();
    bool isFull() const;
    bool isEmpty() const;

protected:
    int size;
    std::string elements[10]{};
};


#endif //HOSPITAL_STACK_H