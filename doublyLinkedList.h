/*
 * Created by : AbdUlRahman Shawareb
 * 10th Jul 2020
 */
#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

#include <iostream>

using namespace std;

template<class Type>
struct Node {
    Type data;
    Node *next;
    Node *prev;
};

template<class Type>
class Iterator {
private:
    Node<Type> *current;
public:
    Iterator();

    Iterator(Node<Type> *ptr);

    Type operator*();

    Iterator<Type> operator++();

    bool operator==(Iterator<Type> &right);

    bool operator!=(Iterator<Type> &right);
};

template<class Type>
Iterator<Type>::Iterator() {
    current = NULL;
}

template<class Type>
Iterator<Type>::Iterator(Node<Type> *ptr) {
    current = ptr;

}

template<class Type>
Type Iterator<Type>::operator*() {
    return current->data;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator++() {
    current = current->next;
    return *this;
}

template<class Type>
bool Iterator<Type>::operator==(Iterator<Type> &right) {
    return (current == right.current);
}

template<class Type>
bool Iterator<Type>::operator!=(Iterator<Type> &right) {
    return (current != right.current);
}

template<class Type>
class doublyLinkedList {
private:
    int sz;
    Node<Type> *head;
    Node<Type> *tail;
public:
    doublyLinkedList();

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

    void reversePrint();

    ~doublyLinkedList();
};

template<class Type>
doublyLinkedList<Type>::doublyLinkedList() {
    sz = 0;
    head = NULL;
    tail = NULL;
}

template<class Type>
Type doublyLinkedList<Type>::front() {
    assert(head != NULL);
    return head->data;
}

template<class Type>
Type doublyLinkedList<Type>::back() {
    assert(tail != NULL);
    return tail->data;
}

template<class Type>
Iterator<Type> doublyLinkedList<Type>::begin() {
    Iterator<Type> temp(head);
    return temp;
}

template<class Type>
Iterator<Type> doublyLinkedList<Type>::end() {
    Iterator<Type> temp(NULL);
    return temp;
}

template<class Type>
void doublyLinkedList<Type>::push_front(Type in) {
    Node<Type> *temp = new Node<Type>();
    temp->data = in;
    temp->prev = NULL;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    sz++;
}

template<class Type>
void doublyLinkedList<Type>::push_back(Type in) {
    Node<Type> *temp = new Node<Type>();
    temp->next = NULL;
    temp->prev = NULL;
    temp->data = in;
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    sz++;
}

template<class Type>
void doublyLinkedList<Type>::insert(Type in, int pos) {
    if (pos > sz) {
        cout << "Invalid position, out of range" << endl;
        return;
    }
    if (pos == 0) {
        push_front(in);
        return;
    }
    if (pos == sz) {
        push_back(in);
        return;
    }
    Node<Type> *temp1 = new Node<Type>();
    Node<Type> *temp2 = new Node<Type>();
    Node<Type> *temp3 = new Node<Type>();
    temp1->next = NULL;
    temp1->prev = NULL;
    temp1->data = in;
    temp2 = head;
    for (int i = 0; i < pos - 1; i++) {
        temp2 = temp2->next;
    }
    temp3 = temp2->next;
    temp1->next = temp3;
    temp3->prev = temp1;
    temp2->next = temp1;
    temp1->prev = temp2;

    sz++;

}

template<class Type>
void doublyLinkedList<Type>::pop_back() {
    if (head == NULL) {
        cout << "List is empty";
        return;
    }
    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        sz--;
    } else {
        Node<Type> *temp = new Node<Type>();
        temp = tail->prev;
        delete tail;
        temp->next = NULL;
        tail = temp;
        sz--;
    }
}

template<class Type>
void doublyLinkedList<Type>::erase(int pos) {
    if (pos >= sz) {
        cout << "Invalid position, out of range" << endl;
        return;
    }
    if (pos == 0) {
        if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
            sz--;
        } else {
            Node<Type> *temp = new Node<Type>();
            temp = head->next;
            temp->prev = NULL;
            delete head;
            head = temp;
            sz--;
        }
    } else if (pos == sz - 1) {
        pop_back();
    } else {
        Node<Type> *temp = new Node<Type>();
        Node<Type> *temp2 = new Node<Type>();
        temp = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        (temp2->next)->prev = temp;
        delete temp2;
        sz--;
    }
}

template<class Type>
bool doublyLinkedList<Type>::find(Type in) {
    Node<Type> *temp = new Node<Type>();
    temp = head;
    while (temp != NULL) {
        if (temp->data == in)
            return true;
        else
            temp = temp->next;
    }
    return false;
}

template<class Type>
void doublyLinkedList<Type>::reverse() {
    if (head == NULL) {
        cout << "List is empty \n";
    } else {
        Node<Type> *current, *prev, *next;
        current = head;
        prev = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    Node<Type> *temp = new Node<Type>();
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    tail = temp;
}

template<class Type>
bool doublyLinkedList<Type>::isEmpty() {
    return (head == NULL);
}

template<class Type>
int doublyLinkedList<Type>::length() {
    return sz;
}

template<class Type>
void doublyLinkedList<Type>::clear() {
    Node<Type> *temp = new Node<Type>();
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
    sz = 0;
}

template<class Type>
void doublyLinkedList<Type>::print() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node<Type> *temp = new Node<Type>();
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template<class Type>
void doublyLinkedList<Type>::reversePrint() {
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node<Type> *temp = new Node<Type>();
    temp = tail;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

template<class Type>
doublyLinkedList<Type>::~doublyLinkedList() {
    clear();
}

#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
