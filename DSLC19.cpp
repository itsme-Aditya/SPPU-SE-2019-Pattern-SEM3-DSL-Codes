#include <iostream>
using namespace std;

class node {
    int prn;
    string name;
    node *next;
    public:
        void display(node *head);
        node *create();
        node *add_begin(node *head);
        node *add_end(node *head);
        node *add_mid(node *head);
        node *del_begin(node *head);
        node *del_end(node *head);
        node *del_mid(node *head);
};

node *node :: create() {
    int i, n;
    node *p, *head;
    head = NULL;
    cout << "Enter number of members:";
    cin >> n;
    for (i = 0; i < n; i ++) {
        if (head == NULL) {
            head = new node;
            cout << "Enter Name and PRN of members:";
            cin >> head->name;
            cin >> head->prn;
            head->next = NULL;
            p = head;
        }
        else {
            p->next = new node;
            p = p->next;
            cout << "Enter Name and PRN of members:";
            cin >> p->name;
            cin >> p->prn;
            p->next = NULL;     
        }
    }
    return head;
}

void node :: display(node *head) {
    node *p;
    for (p = head; p != NULL; p = p->next) {
        cout << "Name: " << p->name << endl;
        cout << "PRN: " << p->prn << endl << endl;
    }
}

node *node::add_begin(node *head) {
    node *q;
    q = new node;
    cout << "Enter Name and PRN of members:";
    cin >> q->name;
    cin >> q->prn;
    q->next = head;
    head = q;
    return head;
}

node *node::add_end(node *head) {
    node *p, *q;
    p = new node;
    cout << "Enter Name and PRN of members:";
    cin >> p->name;
    cin >> p->prn;
    p->next = NULL;
    for (q = head; q->next != NULL; q = q->next);
    q->next = p;
    return head;
}

node *node::add_mid(node *head) {
    node *p, *q;
    int elem;
    cout << "Enter PRN after which you have to add element: ";
    cin >> elem;
    for (q = head; q->prn != elem; q = q->next);
    p = new node;
    cout << "Enter Name and PRN of members:";
    cin >> p->name;
    cin >> p->prn;
    p->next = q->next;
    q->next = p;
    return head;
}

node *node::del_begin(node *head) {
    node *p;
    p = head;
    head = head->next;
    delete p;
    return head;
}

node *node::del_end(node *head) {
    node *p, *q;
    for (q = head; q->next->next != NULL; q = q->next);
    p = q->next;
    delete p;
    q->next = NULL;
    return head;
}

node *node::del_mid(node *head) {
    node *p, *q;
    int elem;
    cout << "Enter PRN to be deleted: ";
    cin >> elem;
    for (q = head; q->next->prn != elem; q = q->next);
    p = q->next;
    q->next = p->next;
    delete p;
    return head;
}

int main() {
    node obj, *head;
    int ch;
    while (true) {
        cout << "----------MENU----------\n1) Create list\n2) Add president\n3) Add seceratery\n4) Add members\n5) Delete president\n6) Delete seceratery\n7) Delete members\n8) Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                head = obj.create();
                obj.display(head);
                break;
            case 2:
                head = obj.add_begin(head);
                obj.display(head);
                break;
            case 3:
                head = obj.add_end(head);
                obj.display(head);
                break;
            case 4:
                head = obj.add_mid(head);
                obj.display(head);
                break;
            case 5:
                head = obj.del_begin(head);
                obj.display(head);
                break;
            case 6:
                head = obj.del_end(head);
                obj.display(head);
                break;
            case 7:
                head = obj.del_mid(head);
                obj.display(head);
                break;
            case 8:
                return 0;
            default:
                cout << "Enter valid choice.";
        }
    }
    return 0;
}
