 /*
Category: Dynamic Programming

Approach:
- Use recursion with memoization where dp[idx] represents the maximum points
  obtainable starting from question idx.
- For each question, there are two choices:
  - Skip the current question and move to the next one.
  - Solve the current question, earn its points, and jump ahead by
    brainpower + 1 positions.
- Compute both choices and store the maximum result in the memo table.
- Memoization ensures each index is processed only once.

Time Complexity: O(n)
Space Complexity: O(n)
 */
using ll = long long;
class Solution {
public:
    ll helper(vector<vector<int>>& questions,ll idx, vector<ll>& memo){
        if(idx >= questions.size()) return 0;
        if(memo[idx] != -1) return memo[idx];
        ll skip = helper(questions, idx + 1, memo);
        ll points = questions[idx][0];
        ll jump = questions[idx][1];
        ll solve = points + helper(questions, idx + jump + 1, memo);
        return memo[idx] = max(skip, solve);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<ll>memo(questions.size() + 1, -1);
        return helper(questions, 0 ,memo);
    }
};