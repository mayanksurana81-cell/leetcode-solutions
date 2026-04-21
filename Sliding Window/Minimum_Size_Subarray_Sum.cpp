/*
Category: Sliding Window
Approach:
Use two pointers to maintain a window with sum >= target. Expand the window by moving right pointer
and shrink it from left while condition is satisfied to find the minimum length subarray.
Track the smallest window length encountered during the process.
Time Complexity: O(n)
Space Complexity: O(1)
Where only constant extra space is used
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int len = 0 , min_len = INT_MAX;
        int i = 0 , j = 0;
        while(j<n){
            sum += nums[j];
            while(sum >= target){
                len = j-i+1;
                min_len = min(min_len , len);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return (min_len == INT_MAX) ? 0 : min_len;
    }
};