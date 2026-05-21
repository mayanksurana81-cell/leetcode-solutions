 /*
Category: Arrays, Index Marking

Approach:
- The array values are used as indices to track visited numbers.
- For every element:
  - Take its absolute value and map it to index = value - 1.
  - If the value at that index is already negative, it means the number
    has been seen before, so it is a duplicate.
  - Otherwise, mark the index as visited by making its value negative.
- Negative marking acts as an in-place frequency tracker without extra space.

Time Complexity: O(n)
Space Complexity: O(1)
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0 ; i<nums.size() ; i++){
            int idx = abs(nums[i]) - 1;
            if(nums[idx] < 0) ans.push_back(idx + 1);
            else nums[idx] *= -1;
        }
        return ans;
    }
};