
/*
Category: Hashing
Approach:
Count frequency of each element using hashmap, then insert frequencies into a set.
If any frequency repeats (already present in set), return false, otherwise all are unique.
Time Complexity: O(n)
Space Complexity: O(n)
Where hashmap and set store up to n elements
*/class Solution {
public:
    bool uniqueOccurrences(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        unordered_set<int>s;
        for(int i = 0 ; i<n ;i++){
            m[nums[i]]++;
        }
        for(auto x : m){
            int freq = x.second;
            if(s.find(freq)!=s.end()) return false;
            else s.insert(freq);
        }
        return true;
        
    }
};