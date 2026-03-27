/*
Category: Linked List (Primary)

Approach:
Count total nodes and process only complete groups of size k.
Reverse each k-sized group and connect them sequentially,
leaving remaining nodes (less than k) unchanged.

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
ListNode* reverse(ListNode* head , int k){
    int cnt = 0;
    ListNode* temp = head;
    ListNode* front = NULL;
    ListNode* prev = NULL;
    while(cnt<k){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
        cnt++;
    }
    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        if(head == NULL || head->next == NULL) return head;
        int n = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp1 = dummy;
        // calculate size
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        //calculate number of last nodes to leave
        int leave = n-(n%k);
        // travel till leave and reverse in chunks
        temp = head;
        for(int i = 1 ; i<=leave ; i += k){
            ListNode* nextTemp = temp;
            int c = 0;
            while(c < k){
                nextTemp = nextTemp->next;
                c++;
            }
            temp1->next = reverse(temp , k);
            temp = nextTemp;
            int cnt = 0;
            while(cnt < k){
                temp1 = temp1->next;
                cnt++;
            }

        }
        temp1->next = temp;
        return dummy->next;
    }
};