
#include <iostream>

using namespace std;

class Stack {
public:
    int arr[5];
    int top;

    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == sizeof(arr) / sizeof(arr[0]) - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        int value = arr[top];
        top--;

        return value;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == sizeof(arr) / sizeof(arr[0]) - 1;
    }
};

int main() {

    Stack s;
    int n;

    cout << "Enter no. of elements to push onto stack: ";
    cin >> n;

    cout << "Pushing elements onto the stack:" << endl;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push(x);
    }

    cout << "Top element: " << s.peek() << endl;

    cout << "Is stack empty? ";
    if (s.isEmpty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << "Is stack full? ";
    if (s.isFull())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << "Popped element: " << s.pop() << endl;

    cout << "Top element after pop: " << s.peek() << endl;

    cout << "Remaining elements in stack:" << endl;

    while (!s.isEmpty()) {
        cout << s.pop() << endl;
    }

    cout << "Is stack empty now? ";
    if (s.isEmpty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}