/*
Category: Heap / Hashing
Approach:
Count frequencies using hashmap, then maintain a min heap of size k storing (frequency, element).
If heap size exceeds k, remove smallest frequency element, leaving top k frequent elements.
Time Complexity: O(n log k)
Space Complexity: O(n)
Where hashmap stores all elements and heap stores k elements
*/
class Solution {
public:
typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int , int>mp;
        priority_queue<pi , vector<pi>, greater<pi>> pq;
        for(int ele : nums){
            mp[ele]++;
        }
        for(auto x : mp){
            int ele = x.first;
            int freq = x.second;
            pq.push({freq,ele});
            if(pq.size()>k) pq.pop();
        }
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};