/*
Category: Sliding Window
Approach:
Expand the window with pointer j and allow at most k zero flips. When an extra zero is encountered,
shrink the window from left until one zero is removed, maintaining a valid window implicitly.
Track maximum window length during traversal.
Time Complexity: O(n)
Space Complexity: O(1)
Where only constant extra space is used
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int len = INT_MIN;
        int flip = 0,i = 0 , j = 0;
        while(j<n){
            if(nums[j] == 0){
                if(flip < k){
                    flip++;
                }
                else{
                    len = max(len , j-i);
                    while(nums[i]== 1)i++;
                    i++;
                }
            }
            j++;
        }
        return max(len , j-i);
    }
};