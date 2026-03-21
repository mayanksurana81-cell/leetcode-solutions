/*
Category: Linked List (Primary), Two Pointers (Secondary)

Approach:
Use two pointers with a gap of n nodes. Move fast n steps ahead,
then move both pointers together until fast reaches the end.
Slow will be just before the node to delete.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0 ; i< n ; i++){
            fast = fast->next;
        }
        if(fast == NULL) return head->next;
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast -> next;
        }
        slow->next = slow->next->next;
        return head;

    }
};