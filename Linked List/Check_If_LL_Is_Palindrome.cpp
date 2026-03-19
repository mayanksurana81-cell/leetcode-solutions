/*
Category: Linked List (Primary), Two Pointers (Secondary)

Approach:
Find the middle using slow-fast pointers, reverse the second half,
then compare both halves node by node. If all values match,
the list is a palindrome.

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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = slow;
        ListNode* front = NULL;
        ListNode* prev = NULL;
        //Reverse
        while(curr != NULL){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        //Compare
        ListNode* first = head;
        ListNode* second = prev;
        while(second != NULL){
            if(first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};