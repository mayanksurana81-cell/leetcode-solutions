/*
Category: Dynamic Programming (Top-Down / Memoization)
Approach:
At each index, choose to either rob the current house and skip next or skip current house.
Use memoization to store maximum profit from each index to avoid recomputation.
Time Complexity: O(n)
Space Complexity: O(n)
Where dp array and recursion stack take linear space
*/
class Solution {
public:
int helper(vector<int> &dp, vector<int> &nums , int i){
    if(i >= nums.size()){
        return 0;
    }
    if(dp[i] != -1) return dp[i];
    int take = nums[i] + helper(dp, nums , i+2);
    int skip = helper(dp, nums , i+1);
    return dp[i] = max(take , skip);
}
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() , -1);
        return helper(dp, nums , 0);
    }
};