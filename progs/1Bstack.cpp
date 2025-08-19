#include <iostream>
#include <climits>
using namespace std;

const int MAX = 1000;

class Stack {
 private:
    int top;
    int a[MAX];
 public:
    Stack() { top = -1; }

    bool push(int x){
        if (top >= (MAX-1)) {
            cout << "Stack Overflow";
            return false;
        }else {
            a[++top] = x;
            return true;
        }
    }
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow";
            return INT_MIN;
        } else {
            int x = a[top--];
            return x;
        }
    }
    int peek() {
        if (top < 0) {
            cout << "Stack is Empty";
            return INT_MIN;
        } else {
            int x = a[top];
            return x;
        }
    }
    bool isEmpty() {
        return (top < 0);
    }
    void display() {
        if (top < 0) {
            cout << "Stack is Empty";
            return;
        } else {
            cout << "Stack elements are: ";
            for (int i = top; i >= 0; i--)
            cout << a[i] << " ";
            cout << endl;
        }
    }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << "Top element is: " << s.peek() << endl;
    s.pop();
    s.display();
    return 0;
}