/*
Category: Linked List (Primary), Two Pointers (Secondary)

Approach:
Use two pointers traversing both lists. When one pointer
reaches the end, redirect it to the other list’s head.
They will meet at the intersection node or NULL.

Time Complexity: O(n + m)
Space Complexity: O(1)

Where n = length of list A,
      m = length of list B.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* a = headA;
    ListNode* b = headB;
    while(a != b){
        a = (a == NULL) ? headB : a->next;
        b = (b == NULL) ? headA : b->next;
    }
    return a;
}
};