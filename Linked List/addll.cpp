#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        stack<int> s1;
        stack<int> s2;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        // Put first list values into stack
        while (temp1 != NULL) {
            s1.push(temp1->val);
            temp1 = temp1->next;
        }

        // Put second list values into stack
        while (temp2 != NULL) {
            s2.push(temp2->val);
            temp2 = temp2->next;
        }

        int carry = 0;

        ListNode* head = NULL;

        // Add from right to left
        while (!s1.empty() || !s2.empty() || carry != 0) {

            int value1 = 0;
            int value2 = 0;

            if (!s1.empty()) {
                value1 = s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                value2 = s2.top();
                s2.pop();
            }

            int sum = value1 + value2 + carry;

            int digit = sum % 10;
            carry = sum / 10;

            // Insert new node at beginning
            ListNode* newNode = new ListNode(digit);

            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};

int main() {

    // Create first linked list: 7 -> 2 -> 4 -> 3
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);

    // Create second linked list: 5 -> 6 -> 4
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result linked list
    cout << "Resultant linked list: ";
    while (result != NULL) {
        cout << result->val;
        if (result->next != NULL) {
            cout << " -> ";
        }
        result = result->next;
    }
    cout << endl;

    return 0;
}