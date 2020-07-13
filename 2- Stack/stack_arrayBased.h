/*
 * Created by : AbdUlRahman Shawareb
 * 13th Jul 2020
 */

#ifndef STACK_STACK_ARRAYBASED_H
#define STACK_STACK_ARRAYBASED_H

#include <iostream>

using namespace std;

template<class Type>
class stack_arrayBased {
private:
    int stackTop;
    int maxSize;
    Type *list;
public:
    stack_arrayBased();

    stack_arrayBased(int sz);

    void push(Type in);

    void pop();

    Type top();

    bool isEmpty();

    bool isFull();

    int length();

    void clear();

    void print();

    ~stack_arrayBased();
};

template<class Type>
stack_arrayBased<Type>::stack_arrayBased() {
    maxSize = 100;
    stackTop = -1;
    list = new Type[100];
}

template<class Type>
stack_arrayBased<Type>::stack_arrayBased(int sz) {
    if (sz <= 0) {
        cout << "Size must be positive" << endl;
        exit(0);
    }
    maxSize = 2 * sz;
    stackTop = -1;
    list = new Type[maxSize];

}

template<class Type>
void stack_arrayBased<Type>::push(Type in) {
    if (isFull()) {
        cout << "Stack is full" << endl;
        return;
    }
    stackTop++;
    list[stackTop] = in;
}

template<class Type>
void stack_arrayBased<Type>::pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    }
    stackTop--;
}

template<class Type>
Type stack_arrayBased<Type>::top() {
    if (stackTop == -1) {
        cout << "Stack is empty" << endl;
        exit(0);
    }
    return list[stackTop];
}

template<class Type>
bool stack_arrayBased<Type>::isEmpty() {
    return (stackTop == -1);
}

template<class Type>
bool stack_arrayBased<Type>::isFull() {
    return (stackTop + 1 == maxSize);
}

template<class Type>
int stack_arrayBased<Type>::length() {
    return stackTop + 1;
}

template<class Type>
void stack_arrayBased<Type>::clear() {
    stackTop = -1;
}

template<class Type>
void stack_arrayBased<Type>::print() {
    if (stackTop == -1) {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = stackTop; i >= 0; i--) {
        cout << list[i] << " ";
    }
    cout << endl;

}

template<class Type>
stack_arrayBased<Type>::~stack_arrayBased() {
    delete[] list;
}


#endif //STACK_STACK_ARRAYBASED_H
