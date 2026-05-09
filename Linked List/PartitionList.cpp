/*
Category: Linked List
Approach:
Create two separate lists: one for nodes with values smaller than x and another for nodes greater or equal to x.
Traverse original list, attach nodes to corresponding list, then connect both lists while preserving relative order.
Time Complexity: O(n)
Space Complexity: O(1)
Where only a few extra pointers are used
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* lo = new ListNode(100);
        ListNode* hi = new ListNode(200);
        ListNode* tl = lo;
        ListNode* th = hi;
        ListNode* t = head;
        while(t!=NULL){
            if(t->val<x){
                tl->next = t;
                tl = tl->next;
                t = t->next;
            }
            else{
                th->next = t;
                th = th->next;
                t = t->next;
            }
        }
        th->next = NULL;
        tl->next = hi->next;
        return lo->next;
    }
};