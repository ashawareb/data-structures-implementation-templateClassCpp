/*
 * Created by : AbdUlRahman Shawareb
 * 19th Aug 2020
 */

#ifndef QUEUE_QUEUE_ARRAYBASED_H
#define QUEUE_QUEUE_ARRAYBASED_H

#include <iostream>

using namespace std;

template<class Type>
class queue_arrayBased {
private:
    Type *list;
    int queueFront;
    int queueRear;
    int maxSize;
    int count;
public:
    queue_arrayBased();

    queue_arrayBased(int sz);

    void push(Type in);

    void pop();

    bool isEmpty();

    bool isFull();

    Type front();

    Type back();

    int length();

    void clear();

    void print();

    ~queue_arrayBased();

};

template<class Type>
queue_arrayBased<Type>::queue_arrayBased() {
    maxSize = 100;
    queueFront = -1;
    queueRear = -1;
    count = 0;
    list = new Type[100];
}

template<class Type>
queue_arrayBased<Type>::queue_arrayBased(int sz) {
    if (sz <= 0) {
        cout << "Size must be positive" << endl;
        exit(0);
    }
    maxSize = 2 * sz;
    queueFront = -1;
    queueRear = -1;
    count = 0;
    list = new Type[maxSize];
}

template<class Type>
void queue_arrayBased<Type>::push(Type in) {
    if (isFull()) {
        cout << "Queue is full" << endl;
    } else if (isEmpty()) {
        queueFront = queueRear = 0;
    } else {
        queueRear = (queueRear + 1) % maxSize;
    }
    list[queueRear] = in;
    count++;
}

template<class Type>
void queue_arrayBased<Type>::pop() {
    if (!isEmpty()) {
        queueFront = (queueFront + 1) % maxSize;
        count--;
    } else {
        cout << "Queue is empty" << endl;
    }
}

template<class Type>
bool queue_arrayBased<Type>::isEmpty() {
    return (count == 0);
}

template<class Type>
bool queue_arrayBased<Type>::isFull() {
    return (count == maxSize);
}

template<class Type>
Type queue_arrayBased<Type>::front() {
    if (queueFront == -1) {
        cout << "Queue is empty" << endl;
        exit(0);
    }
    return list[queueFront];
}

template<class Type>
Type queue_arrayBased<Type>::back() {
    if (queueRear == -1) {
        cout << "Queue is empty" << endl;
        exit(0);
    }
    return list[queueRear];
}

template<class Type>
int queue_arrayBased<Type>::length() {
    return count;
}

template<class Type>
void queue_arrayBased<Type>::clear() {
    queueFront = -1;
    queueRear = -1;
    count = 0;
}

template<class Type>
void queue_arrayBased<Type>::print() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        for (int i = queueFront; i <= queueRear; i++) {
            cout << list[i] << " ";
        }
        cout << endl;
    }
}

template<class Type>
queue_arrayBased<Type>::~queue_arrayBased() {
    delete[] list;
}

#endif //QUEUE_QUEUE_ARRAYBASED_H
