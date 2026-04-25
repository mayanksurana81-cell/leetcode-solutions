/*
Category: Heap / Priority Queue
Approach:
Use a max heap to always pick the two largest stones, smash them, and push back their difference if non-zero.
Repeat until at most one stone remains, which is the result.
Time Complexity: O(n log n)
Space Complexity: O(n)
Where heap stores all elements
*/
class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        if(arr.size()==1) return arr[0];
        priority_queue<int> pq;
        for(int ele : arr){
            pq.push(ele);
        }
        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int diff = abs(a-b);
            if(diff>0)pq.push(diff);
        }
        if(pq.size()==0)return 0;
        return pq.top();
    }
};