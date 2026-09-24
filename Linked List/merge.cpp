#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

int main() {

    // First sorted list
    Node* first = new Node{1, nullptr};
    first->next = new Node{2, nullptr};
    first->next->next = new Node{4, nullptr};

    // Second sorted list
    Node* second = new Node{1, nullptr};
    second->next = new Node{3, nullptr};
    second->next->next = new Node{4, nullptr};

    // Dummy node
    Node* dummy = new Node{-1, nullptr};

    // Current pointer
    Node* current = dummy;

    // Compare both lists
    while(first != nullptr && second != nullptr) {

        if(first->data <= second->data) {

            current->next = first;
            first = first->next;

        }
        else {

            current->next = second;
            second = second->next;
        }

        current = current->next;
    }

    // Attach remaining nodes
    if(first != nullptr) {
        current->next = first;
    }
    else {
        current->next = second;
    }

    // Print merged list
    Node* temp = dummy->next;

    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}