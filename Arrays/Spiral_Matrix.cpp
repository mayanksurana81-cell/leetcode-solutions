/*
Category: Matrix (Primary)

Approach:
Traverse the matrix layer by layer using four boundaries
(min row, max row, min col, max col). Move in four directions
(right, down, left, up) and shrink boundaries after each step.

Time Complexity: O(m * n)
Space Complexity: O(1) (excluding output)

Where m = number of rows,
      n = number of columns.
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return{};
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int minr = 0 , minc = 0 , maxr = m-1 , maxc = n-1;
        while(minr <= maxr && minc <= maxc){
            //Right
            for(int i = minc ; i<=maxc ; i++){
                ans.push_back(matrix[minr][i]);
            }
            minr++;
            if(minr > maxr || minc > maxc) break;
            // down
            for(int i = minr ; i<=maxr ; i++){
                ans.push_back(matrix[i][maxc]);
            }
            maxc--;
            if(minr > maxr || minc > maxc) break;
            //left
            for(int i = maxc ; i>=minc ; i--){
                ans.push_back(matrix[maxr][i]);
            }
            maxr--;
            if(minr > maxr || minc > maxc) break;
            //up
            for(int i = maxr ; i>= minr ; i--){
                ans.push_back(matrix[i][minc]);
            }
            minc++;
            if(minr > maxr || minc > maxc) break;
        }
        return ans;
    }
};