/*
Category: Heap / Priority Queue
Approach:
Maintain a min heap of size k to keep track of k largest elements.
Push each element and remove smallest when size exceeds k, leaving kth largest at top.
Time Complexity: O(n log k)
Space Complexity: O(k)
Where heap stores at most k elements
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int> , greater<int> > pq;
        for(int i = 0 ; i<nums.size() ; i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
        
    }
};