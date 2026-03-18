/*
Category: Linked List (Primary)

Approach:
Copy the value of the next node into the current node,
then delete the next node by updating pointers. This
effectively removes the given node without access to head.

Time Complexity: O(1)
Space Complexity: O(1)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
};