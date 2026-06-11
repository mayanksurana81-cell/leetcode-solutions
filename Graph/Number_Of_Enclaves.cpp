 /*
Category: Graph, Depth First Search, Matrix

Approach:
- Any land cell connected to the boundary cannot be an enclave.
- Traverse all boundary cells and start DFS from every boundary land cell.
- During DFS:
  - Mark all connected land cells as water by changing their value to 0.
- After removing all boundary-connected land, traverse the grid again.
- Count the remaining land cells, as these are completely enclosed and cannot reach the boundary.

Time Complexity: O(m × n)
Space Complexity: O(m × n)
 */
class Solution {
    int m,n;
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,-1,0,1};
    void dfs(int i, int j, vector<vector<int>>& grid){
        if(i == 0 || i >= m || j == 0 || j >= n || grid[i][j] == 0) return;
        grid[i][j] = 0;
        for(int d = 0; d < 4; d++){
            dfs(i + dx[d], j + dy[d], grid);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1) dfs(i,j,grid);
            }
        }
        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};