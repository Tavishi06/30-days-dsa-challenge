#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* temp = head;

        while (temp != NULL && temp->next != NULL) {

            if (temp->val == temp->next->val) {

                ListNode* toDelete = temp->next;

                temp->next = toDelete->next;

                delete toDelete;
            }
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};

int main() {

    // Create a sorted linked list with duplicates
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution solution;
    ListNode* result = solution.deleteDuplicates(head);

    // Print the modified list
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}