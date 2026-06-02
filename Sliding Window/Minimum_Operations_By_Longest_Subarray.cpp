 /*
Category: Arrays, Sliding Window

Approach:
- Instead of removing elements from both ends, find the longest subarray
  whose sum equals (totalSum - x).
- Any elements outside this subarray are the ones removed.
- Use a sliding window to maintain the current subarray sum.
- Expand the window with the right pointer and shrink it from the left
  whenever the sum exceeds the required value.
- Track the maximum length subarray having sum equal to (totalSum - x).
- The minimum operations required are:
  total array length - longest valid subarray length.

Time Complexity: O(n)
Space Complexity: O(1)
 */
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int i = 0 , j = 0;
        int winlen = -1;
        int totalsum = 0;
        for(int ele : nums) totalsum += ele;
        int reqsum = totalsum - x;
        int winsum = 0;
        while(j<n){
            winsum += nums[j];
            while(i <= j && winsum > reqsum){
                winsum -= nums[i];
                i++;
            }
            if(winsum == reqsum){
                winlen = max(winlen , j-i+1);
            }
            j++;
        }
        return (winlen == -1) ? -1 : n-winlen;
    }
};