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