 /*
Category: Graph, Degree Counting

Approach:
- Maintain two arrays:
  - in[i]  -> number of people who trust person i.
  - out[i] -> number of people person i trusts.
- Traverse the trust relationships and update the indegree and outdegree counts.
- A town judge must:
  - Be trusted by exactly n-1 people.
  - Trust nobody.
- Iterate through all people and return the one satisfying:
  in[i] == n - 1 and out[i] == 0.
- If no such person exists, return -1.

Time Complexity: O(n + m)
Space Complexity: O(n)
 */
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n+1,0),out(n+1,0);
        for(auto e : trust){
            out[e[0]]++;
            in[e[1]]++;
        }
        int ans = -1;
        for(int i = 1; i<n+1; i++){
           if (in[i] == n - 1 && out[i] == 0) return i;
        }
        return -1;
    }
};