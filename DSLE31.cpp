#include <iostream>
#define SIZE 20
using namespace std;

class deque {
    int data[SIZE];
    int f, r, count;
public:
    deque() {
        f = r = -1;
        count = 0;
    }
    void add_f(int item) {
        if (f == -1) {
            f = r = 0;
            data[f] = item;
            count++;
        }
        else if ((f == 0) && r < (SIZE - 1)) {
            for (int i = count; i > 0; i--) {
                data[i] = data[i - 1];
            }
            data[0] = item;
            count++;
            r++;
        }
        else if (f > 0) {
            f--;
            data[f] = item;
            count++;
        }
        else {
            cout << "The queue is full";
        }
    }
    void add_r(int item) {
        if (f == -1) {
            f = r = 0;
            data[f] = item;
            count++;
        }
        else if (r >= (SIZE - 1) && f > 0) {
            for (int i = SIZE - count; i = (SIZE - 1); i++) {
                data[i - 1] = data[i];
            }
            data[SIZE - 1] = item;
            count++;
            f--;
        }
        else if (r < (SIZE - 1)) {
            r++;
            data[r] = item;
            count++;
        }
        else {
            cout << "The queue is full";
        }
    }
    void del_f() {
        int item;
        if (f == -1) {
            cout << "The queue is empty";
        }
        else {
            item = data[f];
            f++;
            count--;
            if (f <= r) {
                cout << "The item " << item << " deleted";
            }
            else {
                cout << "The item " << item << " deleted";
                f = r = -1;
            }
        }
    }
    void del_r() {
        int item;
        if (f == -1) {
            cout << "The queue is empty";
        }
        else {
            item = data[r];
            r--;
            count--;
            if (r >= f) {
                cout << "The item " << item << " deleted";
            }
            else {
                cout << "The item " << item << " deleted";
                f = r = -1;
            }
        }
    }
    void display() {
        if (f == -1) {
            cout << "The queue is empty";
        }
        else {
            for (int i = f; i <= r; i++) {
                cout << data[i] << " ";
            }
        }
    }
};
int main() {
    int ch, x, y;
    deque obj;
    while (true) {
        cout  << "\n\nF enqueue";
        cout  << "\nR enqueue ";
        cout  << "\nDisplay ";
        cout  << "\nF dequeue ";
        cout  << "\nR dequeue ";
        cout  << "\nExit ";
        cout  << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter data: ";
                cin >> x;
                obj.add_f(x);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> y;
                obj.add_r(y);
                break;
            case 3:
                cout << "\n\n";
                obj.display();
                break;
            case 4:
                obj.del_f();
                break;
            case 5:
                obj.del_r();
                break;
            case 6:
                return 0;
            default:
                cout << "Enter valid choice";
        }
    }
    return 0;
}
