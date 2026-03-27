/*
Category: Linked List (Primary)

Approach:
Compute length and reduce k using modulo. Find the new tail
at (n-k-1) position, make list circular, then break it to
form the rotated list with updated head.

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || head->next == NULL) return head;

        ListNode* temp = head;
        int n = 0;
        while(temp->next != NULL){
            n++;
            temp = temp->next;
        }
        n = n+1;
        k = k%n;
        if(k == 0) return head;
        ListNode* tail = temp;
        temp = head;
        for(int i = 0 ; i<(n-k-1) ; i++){
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        tail->next = head;
        temp->next = NULL;
        return newHead;
    }
};