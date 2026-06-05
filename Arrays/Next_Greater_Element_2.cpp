 /*
Category: Stack, Monotonic Stack

Approach:
- Treat the array as circular by traversing it twice from right to left.
- Use modulo indexing (i % n) to access elements cyclically.
- Maintain a decreasing stack containing potential next greater elements.
- For each element:
  - Remove all elements from the stack that are smaller than or equal to it.
  - The stack top, if present, is the next greater element.
  - Otherwise, the answer remains -1.
- Push the current element into the stack for future comparisons.
- Traversing twice ensures elements can find greater values appearing at the beginning of the array.

Time Complexity: O(n)
Space Complexity: O(n)
 */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n ,-1);
        for(int i = n*2-1 ; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i%n]) st.pop();
            ans[i%n] = st.empty() ? -1 : st.top();
            st.push(nums[i%n]);
        }
        return ans;

    }
};