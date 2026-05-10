/*
Category: Array / Dynamic Programming
Approach:
Build Pascal’s Triangle row in-place using a single vector initialized with 1s.
For each new row, update elements from right to left so previous row values are not overwritten before use.
Time Complexity: O(rowIndex^2)
Space Complexity: O(rowIndex)
Where only one row vector is maintained throughout computation
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1); // Initialize the row vector with 1s
        
        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j) {
                row[j] += row[j - 1]; // Update each element in the current row
            }
        }
        
        return row;
    }
};