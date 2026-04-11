/*
Category: Recursion / Backtracking
Approach:
Generate subsets while skipping duplicates by sorting and ignoring repeated elements at same recursion level.
Uses backtracking to build unique subsets.
Time Complexity: O(2^n)
Space Complexity: O(n)
Where recursion depth is n and output stores all unique subsets
*/
class Solution {
public:void helper(vector<vector<int>> &ans ,vector<int> &v , vector<int>& nums , int i){
        ans.push_back(v);
    for(int idx = i ; idx <nums.size() ; idx++){
        if(idx > i && nums[idx] == nums[idx-1]) continue;
    
    v.push_back(nums[idx]);
    helper(ans , v , nums , idx+1);
    v.pop_back();
    }
    // helper(ans , v , nums , i+1);

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        helper(ans , v , nums , 0);
        return ans;
    }
};