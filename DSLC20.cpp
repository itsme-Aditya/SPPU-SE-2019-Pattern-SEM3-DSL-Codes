#include <iostream>
using namespace std;

class node {
public:
    node *next, *previous;
    int seat, status;
    string id;
};
class cinemax {
public:
    node *head, *tail, *temp;
    cinemax() {
        head = NULL;
    }
    void create();
    void display();
    void book();
    void cancel();
    void avail();
};
void cinemax::create() {
    int i = 1;
    temp = new node;
    temp->seat = 1;
    temp->status = 0;
    temp->id = "NULL";
    head = tail = temp;
    for (i = 2; i <= 70; i++) {
        node *p;
        p = new node;
        p->seat = i;
        p->status = 0;
        p->id = "NULL";
        tail->next = p;
        p->previous = tail;
        tail = p;
        tail->next = head;
        head->previous = tail;
    }
}
void cinemax::display() {
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "                           SCREEN THIS WAY                        \n";
    cout << "-------------------------------------------------------------------------\n";
    int count = 0;
    temp = head;
    while (temp->next != head) {
        if (temp->seat / 10 == 0) {
            cout << "S0" << temp->seat << ": ";
        }
        else {
            cout << "S" << temp->seat << ": ";
        }
        if (temp->status == 0) {
            cout << "|___|";
        }
        else {
            cout << "|_B_|";
        }
        count++;
        if (count % 7 == 0) {
            cout << endl;
        }
        temp = temp->next;
    }
    cout << "S" << temp->seat << ": ";
    if (temp->status == 0) {
            cout << "|___|";
        }
        else {
            cout << "|_B_|";
        }
}
void cinemax::book() {
    int x;
    string y;
    cout << "\nEnter seat to book: ";
    cin >> x;
    cout << "Enter your id: ";
    cin >> y;
    temp = head;
    while (temp->seat != x) {
        temp = temp->next;
    }
    if (temp->status == 1) {
        cout << "Seat already boked";
    }
    else {
        temp->status = 1;
        temp->id = y;
        cout << "The seat " << x << " booked";
    }
}
void cinemax::cancel() {
    int x;
    string y;
    temp = head;
    label:
    cout << "\nEnter seat number to cancel: ";
    cin >> x;
    if (x < 1 || x > 70) {
        cout << "Enter valid seat number";
        goto label;
    }
    while (temp->seat != x) {
        temp = temp->next;
    }
    if (temp->status == 0) {
        cout << "\nSeat not booked";
    }
    else {
        cout << "Enter your id: ";
        cin >> y;
        if (y == temp->id) {
            temp->status = 0;
            temp->id = "NULL";
            cout << "\nThe seat " << x << " canceled";
        }
        else {
            cout << "Incorrect id, seat cannot be cancelled";
        }
    }
}
void cinemax::avail() {
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "                           SCREEN THIS WAY                        \n";
    cout << "-------------------------------------------------------------------------\n";
    int count = 0;
    temp = head;
    while (temp->next != head) {
        if (temp->seat / 10 == 0) {
            cout << "S0" << temp->seat << ": ";
        }
        else {
            cout << "S" << temp->seat << ": ";
        }
        if (temp->status == 0) {
            cout << "|___|";
        }
        else {
            cout << "";
        }
        count++;
        if (count % 7 == 0) {
            cout << endl;
        }
        temp = temp->next;
    }
    cout << "S" << temp->seat << ": ";
    if (temp->status == 0) {
            cout << "|___|";
        }
        else {
            cout << "";
        }
}
int main() {
    cinemax obj;
    int ch;
    obj.create();
    obj.display();
    while (true) {
        cout << "\n----------------------------CINEMAX THEATRE----------------------------\n1) Status\n2) Book seat\n3) Cancel seat\n4) Available seats\n5) Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                obj.display();
                break;
            case 2:
                obj.book();
                break;
            case 3:
                obj.cancel();
                break;
            case 4:
                obj.avail();
                break;
            case 5:
                return 0;
            default:    
                cout << "Enter valid choice";
        }
    }
    return 0;
}
