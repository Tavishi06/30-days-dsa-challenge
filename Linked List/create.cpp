#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

int main() {

    // Creating nodes
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // Giving data
    first->data = 10;
    second->data = 20;
    third->data = 30;

    // Connecting nodes
    first->next = second;
    second->next = third;
    third->next = NULL;

    // First node of linked list
    Node* head = first;


    // ---------------- DISPLAY ----------------

    cout << "Original Linked List: ";

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;


    // ---------------- INSERT AT BEGINNING ----------------

    Node* newNode = new Node();

    newNode->data = 5;
    newNode->next = head;

    head = newNode;

    cout << "After inserting 5 at beginning: ";

    temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;


    // ---------------- INSERT AT END ----------------

    newNode = new Node();

    newNode->data = 40;
    newNode->next = NULL;

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    cout << "After inserting 40 at end: ";

    temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;


    // ---------------- INSERT AT POSITION ----------------
    // Insert 25 at position 4

    newNode = new Node();

    newNode->data = 25;

    temp = head;

    // Move to node before position 4
    for (int i = 1; i < 3; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "After inserting 25 at position 4: ";

    temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;


    // ---------------- DELETE FROM BEGINNING ----------------

    temp = head;

    head = head->next;

    delete temp;

    cout << "After deleting from beginning: ";

    temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;


    // ---------------- DELETE FROM END ----------------

    temp = head;

    // Move to second-last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;

    temp->next = NULL;

    cout << "After deleting from end: ";

    temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;


    // ---------------- DELETE FROM POSITION ----------------
    // Delete position 3

    temp = head;

    // Move to node before position 3
    for (int i = 1; i < 2; i++) {
        temp = temp->next;
    }

    Node* toDelete = temp->next;

    temp->next = toDelete->next;

    delete toDelete;

    cout << "After deleting position 3: ";

    temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;


    return 0;
}