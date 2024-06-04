#include <iostream>
using namespace std;

class queue {
    int data[20];
    int f, r;
public:
    queue() {
        f = -1;
        r = -1;
    }
    int isfull() {
        if (r >= 19) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int isempty() {
        if (f == -1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    void enqueue(int x) {
        if (isfull() == 1) {
            cout << "The queue is already full.";
        }
        else {
            if (isempty() == 1) {
                f++;
            }
            r++;
            data[r] = x;
        }
    }
    void dequeue() {
        int x;
        if (isempty() == 1) {
            cout << "The queue is already empty.";
        }
        else {
            x = data[f];
            f++;
            cout << "The job " << x << " is deleted.";
        }
    }
    void display() {
        for (int i = f; i <= r; i++) {
            cout << data[i] << " ";
        }
    }
};

int main() {
    int job, ch;
    queue q;
    
    while (true) {
        cout << "--------------MENU--------------\nChoices:\n1) Add job\n2) Delete job\n3) Display job\n4) Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch(ch) {
            case 1:
                cout << "Enter job to add: ";
                cin >> job;
                q.enqueue(job);
                break;
            case 2:
                cout << endl;
                q.dequeue();
                cout << endl << endl;
                break;
            case 3:
                cout << endl;
                q.display();
                cout << endl << endl;
                break;
            case 4:
                exit(0);
            default:
                cout << "Enter valid choice.";
                break;
        }
    }
    return 0;
}
