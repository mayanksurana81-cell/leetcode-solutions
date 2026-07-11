/*
Category: Stack, Monotonic Stack, Array

Approach:
- Compute the total contribution of each element as the maximum of all subarrays using previous greater and next greater indices.
- Similarly, compute the total contribution of each element as the minimum using previous smaller and next smaller indices.
- Use monotonic stacks with appropriate comparisons to correctly handle duplicate values.
- The required sum of subarray ranges is obtained by subtracting the total minimum contribution from the total maximum contribution.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    long long subarr_max(vector<int>& nums){
        int n = nums.size();
        vector<int> nge(n);
        vector<int> pge(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }     
        long long sum = 0;
        for(int i = 0; i < n; i++){
            long long left = i - pge[i];
            long long right = nge[i] - i;
            sum = (sum + (left * right * 1LL * nums[i]));
        }   
        return sum;
    }
    long long subarr_min(vector<int>& nums){
        int n = nums.size();
        vector<int> pse(n);
        vector<int> nse(n);
        stack<int> st;
        for(int i = 0; i <n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long sum = 0;
        for(int i = 0; i < n; i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            sum = (sum + (left * right * 1LL* nums[i]));
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return subarr_max(nums) - subarr_min(nums);
    }
};