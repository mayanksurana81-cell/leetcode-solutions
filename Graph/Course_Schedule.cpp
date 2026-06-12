 /*
Category: Graph, Topological Sort

Approach:
- Build a directed graph from the prerequisite relationships.
- Compute the indegree of every course.
- Insert all courses with indegree 0 into a queue.
- Perform Kahn's Algorithm:
  - Remove a course from the queue.
  - Count it as completed.
  - Reduce the indegree of all its dependent courses.
  - If a course's indegree becomes 0, add it to the queue.
- If all courses are processed, it is possible to finish all courses.
- Otherwise, a cycle exists in the dependency graph.

Time Complexity: O(V + E)
Space Complexity: O(V)
 */
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(int neigh : adj[node]){
                Indegree[neigh]--;
                if(Indegree[neigh] == 0) q.push(neigh);
            }
        }
        return count == numCourses;
    }
};