 /*
Category: Linked List

Approach:
- Traverse the sorted linked list using:
  - temp  -> current node being checked
  - curr  -> next node
  - prev  -> last confirmed unique node
- If the current value changes, move all pointers forward normally.
- If duplicate values are found:
  - Skip all nodes having the same value.
  - Connect prev directly to the first different node.
- A flag is used to specially handle the case where duplicates start
  from the head node.
- The logic removes duplicate occurrences while maintaining the linked structure.

Time Complexity: O(n)
Space Complexity: O(1)
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        bool flag = true;
        if(head->val == head->next->val) flag = false;
        ListNode* temp = head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(temp != NULL && curr != NULL){
            if(curr != NULL && curr->val != temp->val){
                prev = temp;
                temp = curr;
                if(curr != NULL)curr = curr->next;
            }
            else {
                while(curr != NULL && curr->val == temp->val) curr = curr->next;
                prev -> next = curr;
                temp = curr;
                if(curr!= NULL) curr = curr->next;
            }
        }
        if(!flag) return head->next;
        return head;
    }
};