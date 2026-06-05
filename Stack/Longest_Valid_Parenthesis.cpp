 /*
Category: Stack, Strings

Approach:
- Use a stack to store indices instead of characters.
- Initialize the stack with -1 to handle valid substrings starting from index 0.
- For every '(':
  - Push its index onto the stack.
- For every ')':
  - Pop the top index.
  - If the stack becomes empty, push the current index as a new base.
  - Otherwise, the length of the current valid substring is
    currentIndex - stack.top().
- Track the maximum valid length encountered during traversal.

Time Complexity: O(n)
Space Complexity: O(n)
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int len = 0;
        for(int i = 0 ; i<s.length(); i++){
            if(s[i] == '(') st.push(i);
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    len = max(len,i-st.top());
                }
            }
        }
return len;
    }
};