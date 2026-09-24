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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* first = headA;
        ListNode* second = headB;

        while (first != second) {

            if (first == NULL) {
                first = headB;
            }
            else {
                first = first->next;
            }

            if (second == NULL) {
                second = headA;
            }
            else {
                second = second->next;
            }
        }

        return first;
    }
};

int main() {

    // Create two linked lists that intersect
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    ListNode* intersection = new ListNode(8);
    headA->next->next = intersection;
    intersection->next = new ListNode(4);
    intersection->next->next = new ListNode(5);

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersection;

    Solution solution;
    ListNode* result = solution.getIntersectionNode(headA, headB);

    if (result != NULL) {
        cout << "Intersection at node with value: " << result->val << endl;
    } else {
        cout << "No intersection." << endl;
    }

    return 0;
}