/*
Category: Matrix (Primary), Binary Search Pattern (Secondary)

Approach:
Start from the top-right corner of the matrix. 
If the current element is greater than target, move left.
If it is smaller, move down. This eliminates one row or
column at each step until the target is found or search ends.

Time Complexity: O(m + n)
Space Complexity: O(1)

Where m = number of rows,
      n = number of columns.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = (m>0) ? matrix[0].size() : 0;
        int i = 0 , j = n-1;
        while(i <m && j >=0){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};