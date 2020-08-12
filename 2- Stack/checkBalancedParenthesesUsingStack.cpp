#include <iostream>
#include<stack>

using namespace std;

bool arePair(char opening, char closing) {
    if (opening == '(' && closing == ')') return true;
    else if (opening == '{' && closing == '}') return true;
    else if (opening == '[' && closing == ']') return true;
    return false;
}

bool checkBalancedParentheses(string exp) {
    stack<char> S;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            S.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (S.empty() || !arePair(S.top(), exp[i]))
                return false;
            else
                S.pop();
        }
    }
    return S.empty();
}

int main() {
    cout << "Enter expression : ";
    string str;
    cin >> str;
    if (checkBalancedParentheses(str))
        cout << "Balanced" << endl;
    else
        cout << "Not balanced" << endl;
    return 0;
}
