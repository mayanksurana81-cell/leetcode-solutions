/*
Category: Sliding Window, Hash Map

Approach:
- Use a sliding window to maintain the current substring.
- Decrease the required count for each character as the right pointer expands.
- Once the window contains at least one 'a', 'b', and 'c', every extension of this window to the right also remains valid.
- Add all such substrings at once using (n - j), then shrink the window from the left to find more valid starting positions.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i = nums2.size()-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i]) st.pop();
            mp[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        for(int ele : nums1){
            ans.push_back(mp[ele]);
        }
        return ans;
    }
};