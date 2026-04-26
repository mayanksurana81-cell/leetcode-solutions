/*
Category: Heap / Priority Queue
Approach:
Traverse the matrix and maintain a max heap of size k storing smallest elements seen so far.
Push each element and remove the largest when size exceeds k, leaving kth smallest at top.
Time Complexity: O(n^2 log k)
Space Complexity: O(k)
Where heap stores at most k elements
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& v, int k) {
        priority_queue<int>pq;
        for(int i = 0 ; i<v.size() ; i++){
            for(int j = 0 ; j<v.size(); j++){
                pq.push(v[i][j]);
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        return pq.top();
        
    }
};