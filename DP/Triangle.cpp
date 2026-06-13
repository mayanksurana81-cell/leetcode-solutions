 /*
Category: Dynamic Programming

Approach:
- Use the triangle itself as the DP table.
- Start from the second-last row and move upward.
- For each cell:
  - The next step can go either directly below or diagonally below-right.
  - Add the minimum of these two values to the current cell.
- After processing all rows, each cell stores the minimum path sum from that position to the bottom.
- The top element finally contains the minimum path sum from the top to the bottom of the triangle.

Time Complexity: O(n²)
Space Complexity: O(1)
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        int ans = 0;
        for(int i = n - 2; i>=0; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                int minval = min(triangle[i+1][j],triangle[i+1][j+1]);
                triangle[i][j] += minval;
            }
        }
        return triangle[0][0];
    }
};