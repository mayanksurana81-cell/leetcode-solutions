 /*
Category: Dynamic Programming

Approach:
- Use recursion with memoization based on:
  - day: current index in the prices array.
  - state: whether buying is allowed (0) or a stock is currently held (1).
- If buying is allowed:
  - Buy the stock and move to the holding state.
  - Or skip the current day.
- If a stock is held:
  - Sell the stock and move back to the buying state.
  - Or continue holding it.
- Store computed results for each (day, state) pair to avoid repeated calculations.
- The answer is the maximum profit achievable starting from day 0 with no stock in hand.

Time Complexity: O(n)
Space Complexity: O(n)
 */
class Solution {
public:
int helper(vector<int>& prices, int day, int state, vector<vector<int>>& memo){
    if(day == prices.size()) return 0;
    if(memo[day][state] != -1) return memo[day][state];
    int profit = 0;
    if(state == 0){
        int buy = -prices[day] + helper(prices, day + 1, 1,memo);
        int skip = helper(prices, day+1,0,memo);
        profit = max(buy, skip);
    }
    else{
            int sell = prices[day] + helper(prices, day + 1, 0,memo);
            int skip = helper(prices, day + 1, 1,memo);
            profit = max(sell, skip);
        }
        memo[day][state] = profit;
        return profit;
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n + 1, vector<int>(2, -1));
        int ans = helper(prices, 0, 0,memo);
        return ans;
    }
};