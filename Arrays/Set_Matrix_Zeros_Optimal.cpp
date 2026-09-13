/*
Category: Array, Matrix, In-Place, Constant Space

Approach:
- Track whether the first row or first column originally contains a zero using separate boolean flags.
- Use the first row and first column as markers for zero-containing rows and columns while scanning the rest of the matrix.
- Traverse the inner matrix again and set an element to zero if its corresponding row or column marker is zero.
- Finally, zero the first row and/or first column based on the original boolean flags.

Time Complexity: O(m * n)
Space Complexity: O(1)
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        bool is_first_row_zero = false;
        bool is_first_col_zero = false;
        for(int i = 0; i < n; i++){
            if(nums[0][i] == 0) {
                is_first_row_zero = true;
                break;
            }
        }
        for(int i = 0; i < m; i++){
            if(nums[i][0] == 0) {
                is_first_col_zero = true;
                break;
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(nums[i][j] == 0){
                    nums[0][j] = 0;
                    nums[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(nums[i][0] == 0 || nums[0][j] == 0){
                    nums[i][j] = 0;
                }
            }
        }
        if(is_first_row_zero){
            for(int i = 0; i < n; i++){
                nums[0][i] = 0;
            }
        }
        if(is_first_col_zero){
            for(int i = 0; i < m; i++){
                nums[i][0] = 0;
            }
        }
    }
};