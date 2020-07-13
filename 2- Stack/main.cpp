#include <iostream>
#include "stack_arrayBased.h"
#include "stack_linkedListBased.h"

using namespace std;

int main() {
    stack_arrayBased<int> s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "Stack : ";
    s.print();
    cout << "Stack top : " << s.top() << endl;
    cout << "Stack size : " << s.length() << endl;
    s.pop();
    cout << "Stack : ";
    s.print();
    cout << "Stack top : " << s.top() << endl;
    cout << "Stack size : " << s.length() << endl;
    s.clear();
    cout << "Stack : ";
    s.print();
    cout << endl;

    cout << "=================================================" << endl << endl;

    stack_linkedListBased<int> arr;
    arr.push(1);
    arr.push(2);
    arr.push(3);
    arr.push(4);
    arr.push(5);
    cout << "Stack : ";
    arr.print();
    cout << "Stack top : " << arr.top() << endl;
    cout << "Stack size : " << arr.length() << endl;
    arr.pop();
    cout << "Stack : ";
    arr.print();
    cout << "Stack top : " << arr.top() << endl;
    cout << "Stack size : " << arr.length() << endl;
    arr.clear();
    cout << "Stack : ";
    arr.print();


    return 0;
}
