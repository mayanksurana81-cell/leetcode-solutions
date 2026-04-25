/*
Category: Heap / Priority Queue
Approach:
Use a max heap storing (absolute difference, value) to keep track of k closest elements to x.
Push each element and remove the farthest when size exceeds k, then sort the result.
Time Complexity: O(n log k + k log k)
Space Complexity: O(k)
Where heap stores at most k elements
*/
class Solution {
public:
typedef pair<int , int>pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pi>pq;
        vector<int>ans;
        for(int i = 0 ; i<arr.size() ; i++){
            int mod = x-arr[i];
            if(mod<0) mod = -1*mod;
            pq.push({mod,arr[i]});
            if(pq.size()>k)pq.pop();
        }
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};