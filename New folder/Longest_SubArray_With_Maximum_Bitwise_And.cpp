 /*
Category: Arrays

Approach:
- Find the maximum element present in the array.
- Traverse the array and count consecutive occurrences of this maximum value.
- If the current element equals the maximum, extend the current streak.
- Otherwise, reset the streak count.
- Track the longest streak encountered during traversal.
- Return the maximum consecutive count of the array's largest element.

Time Complexity: O(n)
Space Complexity: O(1)
 */
class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int mx = *max_element(nums.begin(), nums.end());
        int c = 0, ans = 0;
        for(int  i : nums){
            if(i == mx) c++, ans = max(ans,c);
            else c = 0;
        }
        return ans;
    }
};