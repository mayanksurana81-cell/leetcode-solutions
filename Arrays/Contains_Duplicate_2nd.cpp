/*
Category: Hashing
Approach:
Store last index of each element in a map and check distance between current and previous occurrence.
If the index difference is within k, return true.
Time Complexity: O(n)
Space Complexity: O(n)
Where map stores indices of elements
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        for(int i = 0 ; i<nums.size() ; i++){
            if(mp.count(nums[i])){
                if(i - mp[nums[i]] <= k) return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};
