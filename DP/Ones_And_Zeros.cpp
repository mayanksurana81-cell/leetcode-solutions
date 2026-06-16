 /*
Category: Dynamic Programming

Approach:
- Use recursion with memoization where the state is:
  - i: current string index.
  - m: remaining zeros that can be used.
  - n: remaining ones that can be used.
- For each string:
  - Count the number of zeros and ones it contains.
  - Skip the string and move to the next index.
  - Pick the string if enough zeros and ones remain, then reduce the capacities accordingly.
- Store the maximum result for each (m, n, i) state to avoid recomputation.
- The answer is the maximum number of strings that can be formed within the given zero and one limits.

Time Complexity: O(L × m × n)
Space Complexity: O(L × m × n)
 */
class Solution {
public:
int helper(vector<string>& strs, int m, int n, int i,vector<vector<vector<int>>>& memo){
    if(i == strs.size()) return 0;
    if(memo[m][n][i] != -1) return memo[m][n][i];
    int skip = helper(strs,m,n,i + 1,memo);
    int c0 = count(strs[i].begin(),strs[i].end(),'0');
    int c1 = strs[i].size() - c0;
    int pick = c0 <= m && c1 <= n ? 1 + helper(strs,m - c0, n - c1, i+1,memo) : 0;
    return memo[m][n][i] =  max(pick,skip);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>memo(m + 1, vector<vector<int>>(n + 1, vector<int>(strs.size(), -1)));
            return helper(strs, m, n,0,memo);
    }
};