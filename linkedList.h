/*
 * Created by : AbdUlRahman Shawareb
 */
#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>

using namespace std;
template<class Type>
struct Node {
    Type data;
    Node *link;
};

// error may be in CONST
template<class Type>
class Iterator {
private:
    Node<Type> *current;
public:
    Iterator();

    Iterator(const Node<Type> *ptr);

    Type operator*();

    Iterator<Type> operator++();

    bool operator==(const Iterator<Type> &right);

    bool operator!=(const Iterator<Type> &right);
};

template<class Type>
Iterator<Type>::Iterator() {
    current = NULL;
}

template<class Type>
Iterator<Type>::Iterator(const Node<Type> *ptr) {
    current = ptr;

}

template<class Type>
Type Iterator<Type>::operator*() {
    return current->data;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator++() {
    current = current->link;
    return *this;
}

template<class Type>
bool Iterator<Type>::operator==(const Iterator<Type> &right) {
    return (current == right.current);
}

template<class Type>
bool Iterator<Type>::operator!=(const Iterator<Type> &right) {
    return (current != right.current);
}


template<class Type>
class LinkedList {
private:

    int sz;
    Node<Type> *head;
    Node<Type> *tail;
public:
    LinkedList();

    Type front();

    Type back();

    Iterator<Type> begin();

    Iterator<Type> end();

    void push_front(Type in);

    void push_back(Type in);

    void insert(Type in, int pos);

    void pop_back();

    void erase(int pos);

    bool find(Type in);

    void reverse();

    bool isEmpty();

    int length();

    void clear();

    void print();

    ~LinkedList();
};

template<class Type>
LinkedList<Type>::LinkedList() {
    head = NULL;
    tail = NULL;
    sz = 0;
}

template<class Type>
Type LinkedList<Type>::front() {
    assert(head != NULL);
    return head->data;
}

template<class Type>
Type LinkedList<Type>::back() {
    assert(tail != NULL);
    return tail->data;
}

template<class Type>
Iterator<Type> LinkedList<Type>::begin() {
    Iterator<Type> temp(head);
    return temp;
}

template<class Type>
Iterator<Type> LinkedList<Type>::end() {
    Iterator<Type> temp(NULL);
    return temp;
}

template<class Type>
void LinkedList<Type>::push_front(Type in) {
    Node<Type> *temp = new Node<Type>();
    temp->data = in;
    temp->link = head;
    head = temp;
    if (tail == NULL) {
        tail = temp;
    }
    sz++;
}

template<class Type>
void LinkedList<Type>::push_back(Type in) {
    Node<Type> *temp = new Node<Type>();
    temp->data = in;
    temp->link = NULL;
    if (head == NULL) {
        head = temp;
        tail = temp;
        sz++;
    } else {
        tail->link = temp;
        tail = temp;
        sz++;
    }
}

template<class Type>
void LinkedList<Type>::insert(Type in, int pos) {
    if (pos > sz) {
        cout << "Invalid position, Out of range" << endl;
        return;
    }
    if (pos == 0) {
        push_front(in);
    } else if (pos == sz) {
        push_back(in);
    } else {
        Node<Type> *temp = new Node<Type>();
        Node<Type> *temp2 = new Node<Type>();
        temp->data = in;
        temp->link = NULL;
        temp2 = head;
        for (int i = 0; i < pos - 1; i++) {
            temp2 = temp2->link;
        }
        temp->link = temp2->link;
        temp2->link = temp;
        sz++;
    }
}

template<class Type>
void LinkedList<Type>::pop_back() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node<Type> *temp = new Node<Type>();
    temp = head;
    for (int i = 0; i < sz - 2; i++) {
        temp = temp->link;
    }
    Node<Type> *temp2 = new Node<Type>();
    temp2 = temp->link;
    temp->link = temp2->link;
    sz--;
    delete temp2;
}

template<class Type>
void LinkedList<Type>::erase(int pos) {
    Node<Type> *temp = new Node<Type>();
    temp = head;
    if (pos >= sz) {
        cout << "Invalid position \n";
    } else if (pos == 0) {
        head = temp->link;
        sz--;
        delete temp;
    } else {
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->link;
        }
        Node<Type> *temp2 = new Node<Type>();
        temp2 = temp->link;
        temp->link = temp2->link;
        sz--;
        delete temp2;
    }
}

template<class Type>
bool LinkedList<Type>::find(Type in) {
    Node<Type> *temp = new Node<Type>();
    temp = head;
    while (temp != NULL) {
        if (temp->data == in)
            return true;
        else
            temp = temp->link;
    }
    return false;
}

template<class Type>
void LinkedList<Type>::reverse() {
    if (head == NULL) {
        cout << "List is empty \n";
    } else {
        Node<Type> *current, *prev, *next;
        current = head;
        prev = NULL;
        while (current != NULL) {
            next = current->link;
            current->link = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    Node<Type> *temp = new Node<Type>();
    temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    tail = temp;
}

template<class Type>
bool LinkedList<Type>::isEmpty() {
    if (head == NULL)
        return true;
    return false;
}

template<class Type>
int LinkedList<Type>::length() {
    return sz;
}

template<class Type>
void LinkedList<Type>::clear() {
    Node<Type> *temp = new Node<Type>();
    while (head != NULL) {
        temp = head;
        head = head->link;
        delete temp;
    }
    tail = NULL;
    sz = 0;
}

template<class Type>
void LinkedList<Type>::print() {
    Node<Type> *temp = new Node<Type>();
    temp = head;
    if (temp == NULL) {
        cout << "List is empty " << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
}

template<class Type>
LinkedList<Type>::~LinkedList() {
    clear();
}

#endif //LINKEDLIST_LINKEDLIST_H
