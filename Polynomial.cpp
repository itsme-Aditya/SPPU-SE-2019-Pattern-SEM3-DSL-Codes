#include <iostream>
using namespace std;

class node {
    int coeff, expo;
    node *next;
    public:
        void display(node *head);
        node *create();
        /*node *add_begin(node *head);
        node *add_end(node *head);
        node *add_mid(node *head);
        node *del_begin(node *head);
        node *del_end(node *head);
        node *del_mid(node *head);*/
};

node *node :: create() {
    int i, n;
    node *p, *head;
    head = NULL;
    cout << "Enter number of terms:";
    cin >> n;
    for (i = 0; i < n; i ++) {
        if (head == NULL) {
            head = new node;
            cout << "Enter coefficient and exponent of the term: ";
            cin >> head->coeff;
            cin >> head->expo;
            head->next = NULL;
            p = head;
        }
        else {
            p->next = new node;
            p = p->next;
            cout << "Enter coefficient and exponent of the term: ";
            cin >> p->coeff;
            cin >> p->expo;
            p->next = NULL;     
        }
    }
    return head;
}

void node :: display(node *head) {
    node *p;
    for (p = head; p != NULL; p = p->next) {
        cout << p->coeff << endl;
        cout << p->expo << endl;
    }
}

int main() {
    node obj, obj2, *head1, *head2;
    cout << "-----------------First polynomial-----------------" << endl;
    head1 = obj.create();
    obj.display(head1);
    cout << "-----------------Second polynomial-----------------" << endl;
    head2 = obj2.create();
    obj2.display(head2);
    return 0;
}
