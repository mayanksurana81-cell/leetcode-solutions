/*
Category: Backtracking / Recursion
Approach:
For every index, make two recursive choices:
exclude the current element from subset or include it.
When all elements are processed, store the constructed subset in the final answer.
Time Complexity: O(2^n * n)
Space Complexity: O(n)
Where recursion depth and temporary subset storage take linear space
*/
class Solution {
public:
    void helper(vector<int>& nums , vector<int> ans , vector<vector<int>>& finalAns , int idx ){
            if(idx==nums.size()) {
        finalAns.push_back(ans);
        return;
    }
    helper(nums ,ans ,finalAns , idx+1);
    ans.push_back(nums[idx]);
    helper(nums,ans ,finalAns , idx+1);

}
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> finalAns;
        
        helper(nums , ans , finalAns , 0);
        return finalAns;
    }
};