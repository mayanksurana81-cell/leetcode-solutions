/*
Category: Prefix Sum, Array, Design

Approach:
- Build a prefix sum array where prefix_sum[i] stores the sum of the first i elements.
- For a range [left, right], subtract the prefix sum before left from the prefix sum through right.
- This allows each sumRange query to be answered in constant time after preprocessing.

Time Complexity: O(n) initialization, O(1) per query
Space Complexity: O(n)
*/
class NumArray {
public:
vector<int> prefix_sum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix_sum.resize(n+1,0);
        for(int i = 0; i<nums.size(); i++){
            prefix_sum[i+1] = prefix_sum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
            return prefix_sum[right+1] - prefix_sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */