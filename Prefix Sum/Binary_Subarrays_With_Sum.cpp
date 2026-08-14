/*
Category: Prefix Sum, Hash Map

Approach:
- Maintain a running prefix sum while traversing the binary array.
- For each prefix sum, calculate the required previous prefix sum as (current prefix sum - goal).
- The frequency of this required prefix sum represents the number of subarrays ending at the current index whose sum equals goal.
- Store the frequency of each prefix sum in a hash map for constant-time lookup.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int presum = 0;
        int cnt = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int ele : nums){
            presum += ele;
            int remove = presum - goal;
            cnt += mp[remove];
            mp[presum] += 1;
        }
        return cnt;
    }
};