#pragma once

class Stack
{
private:
    int* array;
    int top;
    int arraySize;
public:
    Stack();
    void push(int element);
    int pop();
    bool isEmpty();
    int getTop();
    int getArraySize();
    Stack (const Stack &other);
    const Stack &operator=(const Stack &other);
    ~Stack();
};
