 /*
Category: Linked List, Randomization

Approach:
- During initialization, traverse the linked list and store all node values
  in a vector.
- To return a random node:
  - Generate a random index in the range [0, n-1].
  - Return the value stored at that index.
- Since every index is chosen with equal probability, each node has an
  equal chance of being selected.

Time Complexity: O(n) for construction, O(1) per getRandom()
Space Complexity: O(n)
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
vector<int> arr;
public:
    Solution(ListNode* head) {
        
        while(head){
            arr.push_back(head->val);
            head=head->next;
        }
    }
    
    int getRandom() {
        int n = arr.size();
        int idx = rand()%n;
        return arr[idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */