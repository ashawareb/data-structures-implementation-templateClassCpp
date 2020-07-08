#include <iostream>
#include "linkedList.h"
using namespace std;
int main() {
    /*
    	created by : AbdUlRahman Shawareb
    	7th Jul 2020
    */
    LinkedList<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    cout << "List after push elements : ";
    arr.print();
    cout << "List size : " << arr.length() << endl;
    arr.push_front(0);
    cout << "List after push element to the first position : ";
    arr.print();
    arr.pop_back();
    cout << "List after delete the last element : ";
    arr.print();
    arr.reverse();
    cout << "List after reverse : ";
    arr.print();
    cout << "List size : " << arr.length() << endl;
    return 0;
}
