 /*
Category: Stack, Monotonic Stack

Approach:
- Traverse the array from right to left.
- Maintain a decreasing stack to represent possible values for the '3' in the 132 pattern.
- Keep a variable third that stores the best candidate for the '2' element.
- For each number:
  - If it is smaller than third, a valid 132 pattern exists.
  - Otherwise, pop all smaller elements from the stack and update third,
    since they can serve as the middle value of the pattern.
- Push the current element onto the stack as a future candidate for '3'.
- If no valid configuration is found, return false.

Time Complexity: O(n)
Space Complexity: O(n)
 */
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int third = INT_MIN;
        for(int i = nums.size() - 1 ; i>= 0; i--){
            if(nums[i] < third) return true;
            while(!st.empty() && st.top() < nums[i]){
                third = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};