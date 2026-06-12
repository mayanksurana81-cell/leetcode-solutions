 /*
Category: Graph, Topological Sort

Approach:
- Build a directed graph from the prerequisite relationships and compute indegrees.
- Insert all courses with indegree 0 into a queue.
- Perform Kahn's Algorithm:
  - Remove a course from the queue and add it to the ordering.
  - Reduce the indegree of its neighbors.
  - Push any neighbor whose indegree becomes 0 into the queue.
- The generated order corresponds to a topological ordering of the graph.
- Since the edges are stored in reverse prerequisite direction, reverse the final ordering to obtain a valid course sequence.
- If all courses are not processed, a cycle exists and no valid ordering is possible.

Time Complexity: O(V + E)
Space Complexity: O(V)
 */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        vector<int> Indegree(numCourses,0);
        for(auto &p : prerequisites){
            adj[p[0]].push_back(p[1]);
            Indegree[p[1]]++;
        }
        for(int i = 0; i < numCourses ; i++){
            if(Indegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(q.front());
            q.pop();
        
            for(int neigh : adj[node]){
                Indegree[neigh]--;
                if(Indegree[neigh] == 0) q.push(neigh);
            }
        }
        reverse(ans.begin(), ans.end());
        return (ans.size() == numCourses) ?ans : vector<int> {};
    }
};