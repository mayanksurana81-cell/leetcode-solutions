/*
Category: Graph, Breadth-First Search (BFS), Multi-Source BFS, Matrix

Approach:
- Initialize a visited matrix and enqueue all initially rotten oranges with time 0.
- Perform multi-source BFS, exploring the four adjacent cells from each rotten orange.
- When an unvisited fresh orange is encountered, mark it visited and enqueue it with time + 1.
- Track the maximum time reached during BFS.
- After traversal, check whether any fresh orange remains unvisited. If so, return -1; otherwise, return the maximum time.

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2 && vis[i][j] == false){
                    q.push({{i,j}, 0});
                    vis[i][j] = true;
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();
            ans = max(ans, time);
            if(j + 1 < n && vis[i][j+1] == false && grid[i][j+1] == 1){
                q.push({{i,j+1}, time + 1});
                vis[i][j+1] = true;
            }
            if(i + 1 < m && vis[i+1][j] == false && grid[i+1][j] == 1){
                q.push({{i+1,j}, time + 1});
                vis[i+1][j] = true;
            }
            if(j - 1 >= 0 && vis[i][j-1] == false && grid[i][j-1] == 1){
                q.push({{i,j-1}, time + 1});
                vis[i][j-1] = true;
            }
            if(i - 1 >= 0 && vis[i-1][j] == false && grid[i-1][j] == 1){
                q.push({{i-1,j}, time + 1});
                vis[i-1][j] = true;
            }
        }    
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !vis[i][j]) return -1;
            }
        }
    return ans;
    }
};