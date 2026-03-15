/*
Category: Matrix (Primary), Binary Search (Secondary)

Approach:
Treat the 2D matrix as a flattened sorted array of size m*n.
Use binary search on indices [0, m*n-1]. Convert the 1D index
to 2D coordinates using row = mid/n and col = mid%n.

Time Complexity: O(log(m*n))
Space Complexity: O(1)

Where m = number of rows,
      n = number of columns.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = (m>0) ? matrix[0].size() : 0;
        int total = m*n;
        int i = 0 , j = total - 1;
        while(i<=j){
            int mid = i + (j-i)/2;
            int row = mid/n;
            int col = mid%n;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) j = mid-1;
            else i = mid + 1;
                }
                return false;
    }
};