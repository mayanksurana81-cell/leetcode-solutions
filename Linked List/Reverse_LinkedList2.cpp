/*
Category: Linked List / Recursion
Approach:
Locate boundaries of the sublist to reverse using pointers before left, at left, at right, and after right.
Detach the sublist, reverse it recursively, then reconnect reversed portion back into the original list.
Handle edge case separately when reversal starts from head.
Time Complexity: O(n)
Space Complexity: O(n)
Where recursion stack for reversing the list takes linear space
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* newhead =  reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
    ListNode* temp = head;
    ListNode* a = NULL;
    ListNode* b = NULL;
    ListNode* c = NULL;
    ListNode* d = NULL;
    int n = 1;
    while(temp){
        if(n==left-1) a = temp;
        if(n==left) b = temp;
        if(n==right) c = temp;
        if(n == right+1) d = temp;
        n++;
        temp = temp->next;
    }
    if(a)a->next = NULL;
    c->next = NULL;
    c = reverseList(b);
    if(a)a->next = c;
    b->next = d;
    if(a)return head;
    return c;
    }
};