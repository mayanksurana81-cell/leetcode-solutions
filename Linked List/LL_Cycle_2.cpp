/*
Category: Linked List (Primary), Two Pointers (Secondary)

Approach:
Use Floyd’s cycle detection. First detect cycle using
slow and fast pointers. Once they meet, move a new pointer
from head and advance both one step to find the cycle entry.

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                ListNode* entry = head;
                while(entry != slow){
                    entry = entry->next;
                    slow = slow -> next;
                }
                return entry;
            }
        }
        return NULL;
    }
};