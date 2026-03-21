/*
Category: Linked List (Primary)

Approach:
Traverse both lists simultaneously, adding corresponding digits
and carry. Create new nodes for the sum. After traversal, if
carry remains, append a new node.

Time Complexity: O(max(n, m))
Space Complexity: O(max(n, m))

Where n = length of l1, m = length of l2.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int carry = 0;
        while(l1 || l2){
            int value = carry;
            if(l1){
                value += l1->val;
                l1 = l1->next;
            }
            if(l2){
                value += l2->val;
                l2 = l2->next;
            }
            carry = value/10;
            temp -> next = new ListNode(value%10);
            temp = temp->next;
        }
        if(carry) temp->next = new ListNode(carry);
        return dummy->next;
    }
};