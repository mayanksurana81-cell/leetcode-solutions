/*
Category: Stack, Monotonic Stack, Array

Approach:
- Find the previous smaller element index and next smaller element index for every array element using two monotonic stacks.
- Use different comparison operators while building the two stacks to correctly handle duplicate values and avoid double counting.
- For each element, compute the number of subarrays in which it is the minimum as (distance to previous smaller) × (distance to next smaller).
- Multiply this contribution by the element's value and accumulate the result modulo 1e9 + 7.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        int mod = (int)(1e9 + 7);
        vector<int> nse(n);//store next smaller idx
        vector<int> pse(n);//store previous smaller idx
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long sum = 0;
        for(int i = 0; i < n; i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            sum = (sum + (left * right * 1LL * arr[i])%mod)%mod;
        }
        return sum;
    }
};