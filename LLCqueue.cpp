#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
};

class queue {
public:
    node *f, *r, *temp;
    queue() {
        f = r = NULL;
    }

    void enqueue(int x) {
        if (f == NULL) {
            temp = new node;
            temp->data = x;
            temp->next = temp;
            f = r = temp;
        }
        else {
            r->next = new node;
            r = r->next;
            r->data = x;
            r->next = f;
        }
    }
    void display() {
        if (f == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        temp = f;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != f);
        cout << endl;
    }
    void dequeue() {
    if (f == NULL) {
        cout << "Queue is empty" << endl;
        return;
    } else if (f == r) { // If only one element is present
        delete f;
        f = r = NULL;
    } else {
        temp = f;
        f = f->next;
        r->next = f;
        delete temp;
    }
}
};
int main() {
    queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue elements: ";
    q.display(); // Display elements: 10 20 30
    return 0;
}
