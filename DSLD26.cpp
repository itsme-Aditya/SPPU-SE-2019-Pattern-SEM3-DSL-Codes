#include <iostream>
using namespace std;

class stack {
public:
    char container[20];
    char expression[20];
    int top;
    stack() {
        top = -1;
    }

    int isfull() {
        return top >= 19;
    }

    int isempty() {
        return top == -1;
    }

    void push(int x) {
        if (isfull()) {
            cout << "The stack is full.";
        } else {
            top++;
            container[top] = x;
        }
    }

    void pop() {
        int x;
        if (isempty()) {
            cout << "The stack is already empty";
        } else {
            x = container[top];
            top--;
            cout << "The item " << x << " popped";
        }
    }

    int check() {
        for (int i = 0; expression[i] != '\0'; i++) {
            if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
                push(expression[i]); // Push actual character onto stack
            }
            else if (expression[i] == '}' || expression[i] == ']' || expression[i] == ')') {
                if (isempty()) {
                    return 0; // Closing bracket found, but stack is empty
                }

                char top_element = container[top]; // Retrieve the top element
                if ((expression[i] == '}' && top_element == '{') ||
                    (expression[i] == ']' && top_element == '[') ||
                    (expression[i] == ')' && top_element == '(')) {
                    pop(); // Matches found, pop from the stack
                } else {
                    return 0; // Mismatched parentheses
                }
            }
        }
        return isempty() ? 1 : 0; // Check if the stack is empty or not after the loop
    }
};

int main() {
    stack obj;
    cout << "Enter expression to check: ";
    cin >> obj.expression;
    int ans = obj.check();
    if (ans == 1) {
        cout << "The expression is balanced.";
    } else {
        cout << "The expression is not balanced.";
    }
    return 0;
}
