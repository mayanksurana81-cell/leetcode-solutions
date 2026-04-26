/*
Category: Heap / Hashing
Approach:
Count frequencies using a hashmap, then use a min heap sorted by frequency and value (descending for ties).
Extract elements from heap and append them freq times to build the sorted result.
Time Complexity: O(n log n)
Space Complexity: O(n)
Where hashmap and heap store up to n elements
*/
class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int> mp;
        for(int ele : nums){
            mp[ele]++;
        }
        priority_queue<pi,vector<pi>,greater<pi> > pq;
        for(auto x : mp){
            int ele = x.first;
            int freq = x.second;
            pq.push({freq,-ele});
        }
        while(pq.size()>0){
            int freq = pq.top().first;
            int ele = -pq.top().second;
            pq.pop();
            for(int i = 0 ; i<freq ; i++){
                ans.push_back(ele);
            }
        }
        return ans;

        
    }
};