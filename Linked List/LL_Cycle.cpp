/*
Category: Linked List (Primary), Two Pointers (Secondary)

Approach:
Use slow and fast pointers. Move slow by one step and fast
by two steps. If a cycle exists, they will eventually meet;
otherwise fast reaches NULL.

Time Complexity: O(n)
Space Complexity: O(1)

Where n = number of nodes.
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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;

    }
};