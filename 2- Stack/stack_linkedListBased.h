/*
 * Created by : AbdUlRahman Shawareb
 * 13th Jul 2020
 */

#ifndef STACK_STACK_LINKEDLISTBASED_H
#define STACK_STACK_LINKEDLISTBASED_H

#include <iostream>

using namespace std;

template<class Type>
struct Node {
    Type data;
    Node *link;
};

template<class Type>
class stack_linkedListBased {
private:
    Node<Type> *stackTop;
    int sz;
public:
    stack_linkedListBased();

    void push(Type in);

    void pop();

    Type top();

    bool isEmpty();

    bool isFull();

    int length();

    void clear();

    void print();

    ~stack_linkedListBased();

};

template<class Type>
stack_linkedListBased<Type>::stack_linkedListBased() {
    stackTop = NULL;
    sz = 0;
}

template<class Type>
void stack_linkedListBased<Type>::push(Type in) {
    Node<Type> *temp = new Node<Type>();
    temp->data = in;
    temp->link = stackTop;
    stackTop = temp;
    sz++;
}

template<class Type>
void stack_linkedListBased<Type>::pop() {
    if (stackTop == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }
    Node<Type> *temp = new Node<Type>();
    temp = stackTop;
    stackTop = stackTop->link;
    delete temp;
    sz--;

}

template<class Type>
Type stack_linkedListBased<Type>::top() {
    if (stackTop == NULL) {
        cout << "Stack is empty" << endl;
        exit(0);
    }
    return stackTop->data;
}

template<class Type>
bool stack_linkedListBased<Type>::isEmpty() {
    return (stackTop == NULL);
}

template<class Type>
bool stack_linkedListBased<Type>::isFull() {
    return false;
}

template<class Type>
int stack_linkedListBased<Type>::length() {
    return sz;
}

template<class Type>
void stack_linkedListBased<Type>::clear() {
    if (stackTop == NULL)
        return;
    Node<Type> *temp = new Node<Type>();
    while (stackTop != NULL) {
        temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
    }
    sz = 0;

}

template<class Type>
void stack_linkedListBased<Type>::print() {
    if (stackTop == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }
    Node<Type> *temp = new Node<Type>();
    temp = stackTop;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
}

template<class Type>
stack_linkedListBased<Type>::~stack_linkedListBased() {
    clear();
}


#endif //STACK_STACK_LINKEDLISTBASED_H
