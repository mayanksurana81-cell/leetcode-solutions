/*
Category: Dynamic Programming (Top-Down / Memoization)
Approach:
Recursive solution with memoization where each state n stores number of ways to reach step n.
Transitions are based on taking 1-step or 2-steps, avoiding recomputation using dp array.
Time Complexity: O(n)
Space Complexity: O(n)
Where dp array and recursion stack both take linear space
*/
class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};