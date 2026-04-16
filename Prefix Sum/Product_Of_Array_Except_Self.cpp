/*
Category: Prefix Sum / Array
Approach:
Compute prefix products and suffix products separately, where each index stores product of elements before and after it.
Multiply corresponding prefix and suffix values to get product of all elements except self.
Time Complexity: O(n)
Space Complexity: O(n)
Where extra arrays are used to store prefix and suffix products
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = 1;
        vector<int> suf(n);
        suf[n-1] = 1;
        vector<int> ans(n);
        for(int i = 1 ; i<nums.size() ; i++){
            pre[i] = nums[i-1]*pre[i-1];
        }
        for(int i = n-2 ; i>=0 ; i--){
            suf[i] = nums[i+1]*suf[i+1];
        }
        for(int i = 0 ; i<n ; i++){
            ans[i] = pre[i]*suf[i];
        }
        return ans;
    }
};