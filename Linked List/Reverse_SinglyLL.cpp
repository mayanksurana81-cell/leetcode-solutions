/*
Category: Linked List (Primary)

Approach:
Iteratively reverse the linked list by changing next pointers.
Keep track of previous (newHead), current, and next node,
and reverse links one by one.

Time Complexity: O(n)
Space Complexity: O(1)

Where n = number of nodes.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        ListNode* front = NULL;
        ListNode* newHead = NULL;
        while(temp != NULL){
            front = temp->next;
            temp->next = newHead;
            newHead = temp;
            temp = front;
        } 
        return newHead;
    }
};