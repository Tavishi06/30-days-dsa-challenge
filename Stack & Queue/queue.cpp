#include <iostream>

using namespace std;

class Queue {
public:
    int arr[5];
    int front;
    int rear;

    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == sizeof(arr) / sizeof(arr[0]) - 1) {
            cout << "Queue Overflow" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        arr[rear] = x;
    }

    int dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        int value = arr[front];
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }

        return value;
    }

    int peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return arr[front];
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    bool isFull() {
        return rear == sizeof(arr) / sizeof(arr[0]) - 1;
    }
};

int main() {

    Queue q;
    int n;

    cout << "Enter no. of elements to enqueue: ";
    cin >> n;

    cout << "Enqueuing elements into the queue:" << endl;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.enqueue(x);
    }

    cout << "Front element: " << q.peek() << endl;

    cout << "Is queue empty? ";
    if (q.isEmpty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << "Is queue full? ";
    if (q.isFull())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << "Dequeued element: " << q.dequeue() << endl;

    cout << "Front element after dequeue: " << q.peek() << endl;

    cout << "Remaining elements in queue:" << endl;

    while (!q.isEmpty()) {
        cout << q.dequeue() << endl;
    }

    cout << "Is queue empty now? ";
    if (q.isEmpty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}