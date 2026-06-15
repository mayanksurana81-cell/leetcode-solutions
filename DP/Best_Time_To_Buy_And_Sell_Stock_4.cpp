 /*
Category: Dynamic Programming

Approach:
- Use recursion with memoization based on:
  - day: current index in the prices array.
  - state: whether buying is allowed (0) or a stock is currently held (1).
  - k: remaining transactions available.
- If buying is allowed:
  - Buy the stock and move to the holding state.
  - Or skip the current day.
- If a stock is held:
  - Sell the stock, consume one transaction, and move back to the buying state.
  - Or continue holding the stock.
- Memoize each (day, state, k) state to avoid recomputation.
- The answer is the maximum profit obtainable starting from day 0 with k transactions available.

Time Complexity: O(n × k)
Space Complexity: O(n × k)
 */
class Solution {
public:
    int helper(vector<int>& prices,int k, int day, int state, vector<vector<vector<int>>>& memo){
    if(day >= prices.size() || k == 0) return 0;
    if(memo[day][state][k] != -1) return memo[day][state][k];
    int profit = 0;
    if(state == 0){
        int buy = -prices[day] + helper(prices,k, day + 1, 1,memo);
        int skip = helper(prices,k, day+1,0,memo);
        profit = max(buy, skip);
    }
    else{
            int sell = prices[day] + helper(prices,k-1, day+1, 0,memo);
            int skip = helper(prices,k, day + 1, 1,memo);
            profit = max(sell, skip);
        }
        memo[day][state][k] = profit;
        return profit;
}
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> memo(n , vector<vector<int>>(2, vector<int>(k+1, -1)));
        int ans = helper(prices,k, 0, 0,memo);
        return ans;
    }
};