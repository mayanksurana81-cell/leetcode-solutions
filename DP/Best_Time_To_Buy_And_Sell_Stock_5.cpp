 /*
Category: Dynamic Programming

Approach:
- Use DP with memoization on:
  - day: current index in the prices array.
  - state:
    - 0 = no active position.
    - 1 = holding a bought stock.
    - 2 = holding a short-sold stock.
  - k: remaining transactions.
- From the neutral state:
  - Buy a stock and move to state 1.
  - Short-sell a stock and move to state 2.
  - Skip the day.
- From the bought state:
  - Sell the stock to complete a transaction.
  - Or continue holding it.
- From the short-sold state:
  - Buy back the stock to close the short position and complete a transaction.
  - Or continue holding the short position.
- Memoize every (day, state, k) combination to avoid recomputation.
- The answer is the maximum profit achievable starting with no active position and k transactions available.

Time Complexity: O(n × k)
Space Complexity: O(n × k)
 */
using ll = long long;
class Solution {
public:
    ll helper(vector<int>& prices,int k, int day, int state, vector<vector<vector<ll>>>& memo){
    if(day == prices.size()){
        if(state == 0) return 0;
        return -1e18;
    }
    if(k == 0) return 0;
    if(memo[day][state][k] != -1) return memo[day][state][k];
    ll profit = 0;
    if(state == 0){
        ll buy = -prices[day] + helper(prices,k, day + 1, 1,memo);
        ll ss = prices[day] + helper(prices,k,day + 1, 2, memo);
        ll skip = helper(prices,k, day+1,0,memo);
        profit = max({buy, skip,ss});
    }
    else if(state == 1){
            ll sell = prices[day] + helper(prices,k-1, day+1, 0,memo);
            ll skip = helper(prices,k, day + 1, 1,memo);
            profit = max(sell, skip);
        }
        else{
            ll buyItBack = -prices[day] + helper(prices,k-1,day + 1, 0,memo);
            ll skip = helper(prices,k,day + 1, 2,memo);
            profit = max(buyItBack,skip);
        }
        memo[day][state][k] = profit;
        return profit;
}
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<ll>>> memo(n , vector<vector<ll>>(3, vector<ll>(k+1, -1)));
        ll ans = helper(prices,k, 0, 0,memo);
        return ans;
    }
};