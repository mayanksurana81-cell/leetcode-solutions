 /*
Category: Arrays, Hash Map, Prefix Sum

Approach:
- Treat:
  - 1 as +1
  - 0 as -1
- Compute a running prefix sum while traversing the array.
- If the same prefix sum appears again, the subarray between the two indices
  has an equal number of 0s and 1s because the net sum change is zero.
- Store the first occurrence of each prefix sum in a hash map.
- For every repeated prefix sum, update the maximum subarray length.
- Initialize sum 0 at index -1 to handle valid subarrays starting from index 0.

Time Complexity: O(n)
Space Complexity: O(n)
 */
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int>mp;
        int len = INT_MIN;
        mp[0] = -1;
        int sum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            sum += nums[i] == 1 ? 1 : -1;
            if(mp.find(sum) != mp.end()) len = max(len , i - mp[sum]);
            else mp[sum] = i;
        }
        return (len==INT_MIN) ? 0 : len;
        
    }
};