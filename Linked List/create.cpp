#include<iostream>
using namespace std;

struct Node{
    
    int data;
    Node* next;

};

int main(){

    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();


    first->data = 2;
    first->next = second;

    second->data = 4;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 8;
    fourth->next = fifth;

    fifth->data = 10;
    fifth->next = NULL;

    Node* head = first;
    Node* temp = head;

    while(temp != NULL){

        cout << temp->data << endl;
        temp = temp->next;
        
    }
    
}