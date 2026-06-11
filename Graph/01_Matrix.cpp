 /*
Category: Graph, Breadth First Search, Matrix

Approach:
- Treat all cells containing 0 as starting points and push them into the queue.
- Initialize their distances as 0 and mark all other cells as unvisited using -1.
- Perform a multi-source BFS:
  - Remove a cell from the queue.
  - Explore its four adjacent neighbors.
  - If a neighbor has not been visited, assign its distance as
    current distance + 1 and push it into the queue.
- Since BFS expands level by level from all zeros simultaneously,
  the first distance assigned to each cell is its minimum distance to a zero.

Time Complexity: O(m × n)
Space Complexity: O(m × n)
 */
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n , -1));
        queue<pair<int,int>> q; 
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        while(!q.empty()){
            int i = q.front().first, j = q.front().second;
            q.pop();
            for(int dir = 0; dir < 4; dir++){
            int ni = i + dx[dir], nj = j + dy[dir];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && ans[ni][nj] == -1){
                ans[ni][nj] = ans[i][j] + 1;
                q.push({ni,nj});
            }
            }
        }
        return ans;
    }
};