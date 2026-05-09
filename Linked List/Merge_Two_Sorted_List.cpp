/*
Category: Linked List / Merge
Approach:
Traverse both sorted linked lists simultaneously and always attach the smaller node
to the merged list. After one list finishes, connect the remaining nodes of the other list.
A dummy node simplifies list construction.
Time Complexity: O(n + m)
Space Complexity: O(1)
Where n and m are lengths of the two linked lists
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* tempA = a;
        ListNode* tempB = b;
        ListNode* c = new ListNode(-1);
        ListNode* tempC = c;
        while(tempA!=NULL && tempB != NULL){
            if(tempA->val <= tempB->val){
                tempC->next = tempA;
                tempC = tempA;
                tempA = tempA->next;
            }
            else{
                tempC->next = tempB;
                tempC = tempB;
                tempB = tempB->next;
            }

        }
        if(tempA == NULL) tempC->next = tempB;
        else tempC->next = tempA;
    return c->next;
    }
};