/*
Category: Stack, Monotonic Stack, Array

Approach:
- Traverse the temperatures array from right to left while maintaining a monotonic decreasing stack of indices.
- Remove all indices whose temperatures are less than or equal to the current temperature since they cannot be the next warmer day.
- If the stack is not empty, the top index represents the next warmer day, and the difference in indices gives the required number of days.
- Push the current index onto the stack for future comparisons.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> st;
        vector<int> ans(n,0);
        for(int i = n - 1; i>=0; i--){
            while(!st.empty() && temp[i] >= temp[st.top()]) st.pop();
            ans[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }  
        return ans;
    }
};