/*
Category: Backtracking, Recursion

Approach:
- Generate all permutations by fixing one position at a time.
- For each recursive call, swap the current element with every possible element from the current index onward.
- Recurse to fill the next position, then backtrack by swapping the elements back to restore the original state.
- Once all positions are fixed, store the current permutation.

Time Complexity: O(n × n!)
Space Complexity: O(n)
*/
class Solution {
public:
void helper(vector<vector<int>>& ans,vector<int>& nums,int i){
    if(i == nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int j = i; j < nums.size(); j++){
        swap(nums[i], nums[j]);
        helper(ans, nums, i + 1);
        swap(nums[i], nums[j]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(ans,nums,0);
        return ans;
    }
};