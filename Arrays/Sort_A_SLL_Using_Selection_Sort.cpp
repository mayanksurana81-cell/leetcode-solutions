class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while(head){
            ListNode* min_node = head;
            ListNode* prev_min = nullptr;
            ListNode* curr = head;
            ListNode* prev = nullptr;
            while(curr){
                if(curr->val < min_node->val){
                    min_node = curr;
                    prev_min = prev;
                }
                prev = curr;
                curr = curr->next;
            }
            if(prev_min == nullptr) head = head->next;
            else prev_min->next = min_node->next;
            tail->next = min_node;
            min_node->next = nullptr;
            tail = tail->next;
        }
        return dummy->next;
    }
};