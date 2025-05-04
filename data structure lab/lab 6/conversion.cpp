/*program to implement infix to postfix and postfix evaluation has the following operations, 1.Get Infix, 2.Convert Infix, 3.Evaluate Postfix, 4.Exit*/
#include "Stack.h"
#include <cctype>
#include <cstdlib>
#include <map>

int precedence(char op) {
    map<char, int> prec = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'%', 2}, {'^', 3}};
    return prec[op];
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
}

//Function to change inflix to postflix
string infixToPostfix(string infix) {
    Stack s;
    string postfix;
    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop();
        } else if (isOperator(ch)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.isEmpty()) {
        postfix += s.pop();
    }
    return postfix;
}

//Function to evaluate Postfix
int evaluatePostfix(string postfix) {
    Stack s;
    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else if (isOperator(ch)) {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '%': s.push(val1 % val2); break;
            }
        }
    }
    return s.pop();
}

int main() {
    string infix;
    int choice;
    do {
        cout << "\nMenu:\n1. Get Infix\n2. Convert Infix to Postfix\n3. Evaluate Postfix\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> infix;
                break;
            case 2:
                if (infix.empty()) {
                    cout << "No infix expression entered.\n";
                } else {
                    cout << "Postfix: " << infixToPostfix(infix) << "\n";
                }
                break;
            case 3:
                if (infix.empty()) {
                    cout << "No infix expression entered.\n";
                } else {
                    cout << "Result: " << evaluatePostfix(infixToPostfix(infix)) << "\n";
                }
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
    return 0;
}
