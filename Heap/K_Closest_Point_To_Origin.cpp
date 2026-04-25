/*
Category: Heap / Priority Queue
Approach:
Maintain a max heap of size k storing points with their squared distance from origin.
Push each point and remove the farthest when size exceeds k, leaving k closest points.
Time Complexity: O(n log k)
Space Complexity: O(k)
Where heap stores at most k elements
*/
class Solution {
public:
typedef pair <int , vector<int>>piv;
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        priority_queue<piv> pq;
        for(vector<int> v : arr){
            int x = v[0] , y = v[1];
            int dis = x*x+y*y;
            pq.push({dis,v});
            if(pq.size()>k)pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};