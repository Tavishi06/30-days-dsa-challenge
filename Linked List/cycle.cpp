#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

int main() {

    // Create nodes
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    // Put data
    first->data = 1;
    second->data = 2;
    third->data = 3;
    fourth->data = 4;

    // Connect nodes
    first->next = second;
    second->next = third;
    third->next = fourth;

    // Create cycle:
    // 4 -> 1
    fourth->next = first;

    // Slow and fast pointers
    Node* slow = first;
    Node* fast = first;

    bool cycle = false;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cycle = true;
            break;
        }
    }

    if (cycle) {
        cout << "Cycle exists" << endl;
    }
    else {
        cout << "No cycle" << endl;
    }

    return 0;
}