/*
Category: Recursion / Backtracking
Approach:
Generate combinations by picking elements multiple times and reducing target, using sorted array for pruning.
Backtracking ensures all valid combinations summing to target are explored.
Time Complexity: O(2^n)
Space Complexity: O(n)
Where recursion depth is proportional to target and combination size
*/
class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int>& nums, vector<int> &v, int k, int i){
        if(k == 0){
            ans.push_back(v);
            return;
        }

        for(int idx = i; idx < nums.size(); idx++){
            if(nums[idx] > k) break;  // pruning

            v.push_back(nums[idx]);
            helper(ans, nums, v, k - nums[idx], idx);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        helper(ans, nums, v, target, 0);
        return ans;
    }
};