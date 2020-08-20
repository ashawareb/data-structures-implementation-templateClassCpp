/*
 * Created by : AbdUlRahman Shawareb
 * 19th Aug 2020
 */

#ifndef QUEUE_QUEUE_LINKEDLISTBASED_H
#define QUEUE_QUEUE_LINKEDLISTBASED_H

#include <iostream>

using namespace std;

template<class Type>
struct Node {
    Type data;
    Node *link;
};

template<class Type>
class queue_linkedListBased {
private:
    Node<Type> *queueFront;
    Node<Type> *queueRear;
    int count;
public:
    queue_linkedListBased();

    void push(Type in);

    void pop();

    bool isEmpty();

    bool isFull();

    Type front();

    Type back();

    int length();

    void clear();

    void print();

    ~queue_linkedListBased();
};

template<class Type>
queue_linkedListBased<Type>::queue_linkedListBased() {
    queueFront = NULL;
    queueRear = NULL;
    count = 0;
}

template<class Type>
void queue_linkedListBased<Type>::push(Type in) {
    Node<Type> *temp = new Node<Type>();
    temp->data = in;
    temp->link = NULL;
    if (isEmpty()) {
        queueFront = temp;
        queueRear = temp;
    } else {
        queueRear->link = temp;
        queueRear = queueRear->link;
    }
    count++;
}

template<class Type>
void queue_linkedListBased<Type>::pop() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    Node<Type> *temp = new Node<Type>();
    temp = queueFront;
    queueFront = queueFront->link;
    delete temp;
    if (queueFront == NULL) {
        queueRear = NULL;
    }
    count--;
}

template<class Type>
bool queue_linkedListBased<Type>::isEmpty() {
    return (queueFront == NULL);
}

template<class Type>
bool queue_linkedListBased<Type>::isFull() {
    return false;
}

template<class Type>
Type queue_linkedListBased<Type>::front() {
    if (queueFront == NULL) {
        cout << "Queue is empty" << endl;
        exit(0);
    }
    return queueFront->data;
}

template<class Type>
Type queue_linkedListBased<Type>::back() {
    if (queueRear == NULL) {
        cout << "Queue is empty" << endl;
        exit(0);
    }
    return queueRear->data;
}

template<class Type>
int queue_linkedListBased<Type>::length() {
    return count;
}

template<class Type>
void queue_linkedListBased<Type>::clear() {
    if (queueFront == NULL) {
        return;
    }
    Node<Type> *temp = new Node<Type>();
    while (queueFront != NULL) {
        temp = queueFront;
        queueFront = queueFront->link;
        delete temp;
    }
    queueRear = NULL;
    count = 0;
}

template<class Type>
void queue_linkedListBased<Type>::print() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    Node<Type> *temp = new Node<Type>();
    temp = queueFront;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
}

template<class Type>
queue_linkedListBased<Type>::~queue_linkedListBased() {
    clear();
}


#endif //QUEUE_QUEUE_LINKEDLISTBASED_H
