#include <iostream>
#include "queue_arrayBased.h"

using namespace std;

int main() {
    queue_arrayBased<int> q(10);
    cout << q.isEmpty() << endl;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.isEmpty() << endl;
    q.print();
    q.pop();
    q.print();
    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.length() << endl;
    return 0;
}
