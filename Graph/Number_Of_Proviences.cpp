 /*
Category: Graph, Depth First Search

Approach:
- Convert the adjacency matrix into an adjacency list representation.
- Maintain a visited array to track explored cities.
- Traverse all cities:
  - If a city is unvisited, start a DFS from it.
  - DFS marks all cities belonging to the same connected component.
- Each new DFS call represents a new province.
- Count the number of DFS traversals performed and return it as the answer.

Time Complexity: O(n²)
Space Complexity: O(n²)
 */
class Solution {
public:
    void dfs(vector<bool> &vis ,vector<vector<int>> &adj, int curr){
        vis[curr] = true;
        for(int neigh : adj[curr]){
            if(vis[neigh] == false) dfs(vis, adj, neigh);
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] == 1) adj[i].push_back(j);
                }
            }
                vector<bool> vis(n,false);
                int c = 0;
                for(int i = 0; i<n; i++){
                    if(vis[i] == false){
                        dfs(vis,adj,i);
                        c++;
                    } 
                }
        return c;
    }
};