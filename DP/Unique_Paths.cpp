 /*
Category: Dynamic Programming

Approach:
- Create a DP grid where grid[i][j] represents the number of ways to reach cell (i, j).
- Initialize the first row and first column with 1 since there is only one way to reach those cells.
- For every other cell:
  - Paths can come either from the top cell or the left cell.
  - Therefore, grid[i][j] = grid[i-1][j] + grid[i][j-1].
- Fill the grid row by row and return the value at the bottom-right corner.

Time Complexity: O(m × n)
Space Complexity: O(m × n)
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        for(int i = 0; i < m; i++) grid[i][0] = 1;
        for(int j = 0; j < n; j++) grid[0][j] = 1;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }
        return grid[m-1][n-1];
    }
};