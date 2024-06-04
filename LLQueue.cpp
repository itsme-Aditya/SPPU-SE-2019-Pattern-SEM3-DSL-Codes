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
            temp->next = NULL;
            f = r = temp;
        }
        else {
            r->next = new node;
            r = r->next;
            r->data = x;
            r->next = NULL;
        }
    }

    void dequeue() {
        if (f == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        temp = f;
        f = f->next;
        delete temp;
    }

    void display() {
        if (f == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        temp = f;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue elements: ";
    q.display(); // Display elements: 10 20 30

    q.dequeue();
    cout << "After dequeue: ";
    q.display(); // Display elements after dequeue: 20 30

    q.enqueue(40);
    cout << "After enqueue: ";
    q.display(); // Display elements after enqueue: 20 30 40

    q.dequeue();
    q.dequeue();
    q.dequeue(); // Removing all elements

    cout << "After dequeuing all elements: ";
    q.display(); // Display: Queue is empty

    return 0;
}