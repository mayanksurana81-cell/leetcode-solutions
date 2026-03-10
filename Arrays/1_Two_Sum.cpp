// LeetCode 1
// Two Sum
// Approach: Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int> mp;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int d = target - nums[i];
            if(mp.count(d)) return{mp[d] , i};
            mp[nums[i]] = i;
        }
        return {-1 , - 1};
    }
};