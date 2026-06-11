 /*
Category: Graph, Depth First Search, Matrix

Approach:
- Traverse every cell of the grid.
- Whenever an unvisited land cell ('1') is found:
  - Start a DFS from that cell.
  - Visit all connected land cells in the four directions.
  - Mark visited land cells as water ('0') to avoid revisiting them.
- Each DFS call completely explores one island.
- Count the number of DFS calls performed, which equals the number of islands.

Time Complexity: O(m × n)
Space Complexity: O(m × n)
 */
class Solution {
    int m,n;
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,-1,0,1};
    void dfs(int i, int j,vector<vector<char>>& grid){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return;
        grid[i][j] = '0';
        for(int dir = 0; dir < 4; dir++){
            dfs(i + dx[dir] , j + dy[dir], grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1') dfs(i ,j, grid), ans++;
            }
        }
        return ans;
    }
};