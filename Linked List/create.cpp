#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Display linked list
void display(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Insert at beginning
void insertAtBeginning(Node*& head, int value) {

    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}

// Insert at end
void insertAtEnd(Node*& head, int value) {

    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    // If linked list is empty
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at a specific position
// Position starts from 1
void insertAtPosition(Node*& head, int value, int position) {

    // Insert at beginning
    if (position == 1) {
        insertAtBeginning(head, value);
        return;
    }

    Node* newNode = new Node();

    newNode->data = value;

    Node* temp = head;

    // Move to node before the required position
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Invalid position
    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteAtBeginning(Node*& head) {

    if (head == NULL) {
        cout << "Linked list is empty!" << endl;
        return;
    }

    Node* temp = head;

    head = head->next;

    delete temp;
}

// Delete from end
void deleteAtEnd(Node*& head) {

    if (head == NULL) {
        cout << "Linked list is empty!" << endl;
        return;
    }

    // Only one node
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    // Move to second-last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;

    temp->next = NULL;
}

// Delete from a specific position
// Position starts from 1
void deleteAtPosition(Node*& head, int position) {

    if (head == NULL) {
        cout << "Linked list is empty!" << endl;
        return;
    }

    // Delete first node
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }

    Node* temp = head;

    // Move to node before the required position
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Invalid position
    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* toDelete = temp->next;

    temp->next = toDelete->next;

    delete toDelete;
}

// Main function
int main() {

    Node* head = NULL;

    // Creating linked list
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    cout << "Initial Linked List: ";
    display(head);


    // Insert at beginning
    insertAtBeginning(head, 5);

    cout << "After inserting 5 at beginning: ";
    display(head);


    // Insert at end
    insertAtEnd(head, 40);

    cout << "After inserting 40 at end: ";
    display(head);


    // Insert at position
    insertAtPosition(head, 25, 4);

    cout << "After inserting 25 at position 4: ";
    display(head);


    // Delete from beginning
    deleteAtBeginning(head);

    cout << "After deleting from beginning: ";
    display(head);


    // Delete from end
    deleteAtEnd(head);

    cout << "After deleting from end: ";
    display(head);


    // Delete from position
    deleteAtPosition(head, 3);

    cout << "After deleting position 3: ";
    display(head);

    return 0;
}