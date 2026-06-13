 /*
Category: Dynamic Programming

Approach:
- Since the houses are arranged in a circle, the first and last houses
  cannot both be robbed.
- Split the problem into two linear House Robber cases:
  - Exclude the last house and compute the maximum profit.
  - Exclude the first house and compute the maximum profit.
- For each case, use the space-optimized House Robber DP:
  - Either rob the current house and add it to the profit two houses back.
  - Or skip the current house and keep the previous maximum profit.
- The maximum of the two cases is the final answer.

Time Complexity: O(n)
Space Complexity: O(1)
 */
class Solution {
public:
int helper(vector<int>& nums){
    int p1 = 0;
    int p2 = 0;
    for(int i = 0; i < nums.size();i++){
        int curr = max(p1,p2+nums[i]);
        p2 = p1;
        p1 = curr;
    }
    return p1;
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int x = nums[n-1];
        nums.pop_back();
        int m1 = helper(nums);
        nums.push_back(x);
        nums.erase(nums.begin());
        int m2 = helper(nums);
        return max(m1,m2);
    }
};