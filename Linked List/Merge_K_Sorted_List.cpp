/*
Category: Linked List / Merge
Approach:
Repeatedly take two sorted linked lists from the array, merge them into one sorted list,
and push the merged list back until only one list remains.
The merge helper combines two sorted lists using pointer manipulation.
Time Complexity: O(Nk)
Space Complexity: O(1)
Where N is total nodes and k is number of lists due to repeated sequential merging
*/
class Solution {
public:
ListNode* merge(ListNode* a , ListNode* b){
    ListNode* tempA = a;
    ListNode* tempB = b;
    ListNode* c = new ListNode(-1);
    ListNode* tempC = c;
    while(tempA!= NULL && tempB != NULL){
        if(tempA->val<=tempB->val){
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
    if(tempA==NULL) tempC->next = tempB;
    else tempC->next = tempA;
    return c->next;

}
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size()==0) return NULL;
        while(arr.size()>1){
            ListNode* a = arr[0];
            arr.erase(arr.begin());
            ListNode* b = arr[0];
            arr.erase(arr.begin());
            ListNode* c = merge(a,b);
            arr.push_back(c);
        }
        return arr[0];
    }
};