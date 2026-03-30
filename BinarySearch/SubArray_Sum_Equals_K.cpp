/*
Category: Array (Primary), Hashing / Prefix Sum (Secondary)

Approach:
Maintain prefix sum and store its frequency in a hashmap.
For each element, check how many times (presum - k) appeared
to count subarrays with sum equal to k.

Time Complexity: O(n)
Space Complexity: O(n)

Where n = number of elements.
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int cnt = 0 , presum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            presum += nums[i];
            int remove = presum-k;
            cnt += mp[remove];
            mp[presum] += 1;
        }
        return cnt;
    }
};