/*
Category: Array, Sorting, Greedy

Approach:
- Sort the intervals by their starting points.
- Keep track of the current interval using curr_start and curr_end.
- If the next interval overlaps with the current interval, extend curr_end to the larger ending point.
- If there is no overlap, store the current interval and start processing the next one.
- Add the final interval after completing the traversal.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        int curr_start = nums[0][0];
        int curr_end = nums[0][1];
        for(int i = 1; i < n; i++){
            if(curr_end>=nums[i][0]){
                curr_end = max(curr_end,nums[i][1]);
            }
            else{
                ans.push_back({curr_start,curr_end});
                curr_start = nums[i][0];
                curr_end = nums[i][1];
            }
        }
        ans.push_back({curr_start,curr_end});
        return ans;
    }
};