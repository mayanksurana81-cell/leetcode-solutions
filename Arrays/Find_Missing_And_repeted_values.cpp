/*
Category: Array, Matrix, In-place Marking

Approach:
- Treat each value as an index in the n × n grid.
- Convert the value to its corresponding row and column using:
  row = (value - 1) / n and col = (value - 1) % n.
- Negate the value at that position to mark that the number has been seen.
- If the target position is already negative, that value is repeated.
- After marking all values, the remaining positive position represents the missing number.

Time Complexity: O(n²)
Space Complexity: O(1) auxiliary space
*/
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans(2);
        for(int i = 0; i<n; i++){
            for(int j = 0; j < n; j++){
                int value = abs(grid[i][j]);
                int row = (value - 1) / n;
                int col = (value - 1) % n;
                if(grid[row][col] < 0){
                    ans[0] = value;
                    continue;
                }
                grid[row][col] *= -1;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 0){
                    ans[1] = i * n + j + 1;
                }
            }
        }
    return ans;
    }
};