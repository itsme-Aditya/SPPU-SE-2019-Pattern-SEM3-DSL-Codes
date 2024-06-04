#include <iostream>
#include <ctype.h>
using namespace std;

class stack {
    int top;
    char container[20];
public:
    stack() {
        top = -1;
    }
    int isempty() {
        if (top == -1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    void push(int x) {
        top ++;
        container[top] = x;
    }
    int pop() {
        int x;
        x = container[top];
        top --;
        return x;
    }
    char topmost() {
        char x;
        x = container[top];
        return x;
    }
    int precedence(int x) {
        if (x == '(') {
            return 0;
        }
        else if (x == '+' || x == '-') {
            return 1;
        }
        else if (x == '/' || x == '*' || x == '%') {
            return 2;
        }
        else {
            return 3;
        }
    }
    void convert(char infix[20], char postfix[20]) {
        int j = 0, i;
        char token, x, e;
        for (i = 0; infix[i] != '\0'; i++) {
            token = infix[i];
            if (isalnum(token)) {
                postfix[j] = token;
                j++;
            }
            else {
                if (token == '(') {
                    push(token);
                }
                else if (token == ')') {
                    while ((x = pop()) != '(') {
                        postfix[j] = x;
                        j ++;
                    }
                }
                else {
                    e = topmost();
                    while (precedence(token) <= precedence(e)&& !isempty()) {
                        x = pop();
                        postfix[j] = x;
                        j ++;
                    }
                    push(token);
                }
            }
        }
        while (!isempty()) {
            x = pop();
            postfix[j] = x;
            j ++;
        }
        postfix[j] = '\0';
    }
};
int main () {
    char infix[20], postfix[20];
    cout << "Enter infix expression: ";
    cin >> infix;
    stack obj;
    obj.convert(infix, postfix);
    cout << "Postfix expression: " << postfix;
    return 0;
}
