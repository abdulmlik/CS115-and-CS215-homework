#include <iostream>
#include <vector>
#include <stack>
//#include <stdlib.h>   // std::system  , C++96
#include <string>
using namespace std;

int priority(char a) {
    int temp;
    if (a == '^')
        temp = 1;
    else  if (a == '*' || a == '/')
        temp = 2;
    else  if (a == '+' || a == '-')
        temp = 3;
    return temp;
}

int main() {
    string infix;
    cout << "Enter an arithmetic expression (\'X+Y*Z/W\'): " << endl;
    getline(cin, infix);

    stack<char> operator_stack;

    vector<char> output;

    for (unsigned i = 0; i < infix.length(); i++) {
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
            while (!operator_stack.empty() && priority(operator_stack.top()) <= priority(infix[i])) {
                output.push_back(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.push(infix[i]);
        } else if (infix[i] == '(') {
            operator_stack.push(infix[i]);
        } else if (infix[i] == ')') {
            while (operator_stack.top() != '(') {
                output.push_back(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.pop();
        } else {
            output.push_back(infix[i]);
        }
    }

    while (!operator_stack.empty()) {
        output.push_back(operator_stack.top());
        operator_stack.pop();
    }
    for(int i = 0; i < int(output.size()); i++)
        cout << output[i];

    cout << endl;
    system("PAUSE");

    return 0;
}

