#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {

        // Base case
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split into two lists
        ListNode* second = slow->next;
        slow->next = NULL;

        // Sort both halves
        ListNode* firstHalf = sortList(head);
        ListNode* secondHalf = sortList(second);

        // Merge sorted halves
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (firstHalf != NULL && secondHalf != NULL) {

            if (firstHalf->val < secondHalf->val) {
                temp->next = firstHalf;
                firstHalf = firstHalf->next;
            }
            else {
                temp->next = secondHalf;
                secondHalf = secondHalf->next;
            }

            temp = temp->next;
        }

        // Attach remaining nodes
        if (firstHalf != NULL) {
            temp->next = firstHalf;
        }
        else {
            temp->next = secondHalf;
        }

        return dummy->next;
    }
};

int main() {

    // 4 → 2 → 1 → 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution solution;

    ListNode* result = solution.sortList(head);

    // Print sorted list
    ListNode* temp = result;

    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}