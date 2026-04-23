/*
Category: Sliding Window
Approach:
Maintain a window allowing at most one zero. Track position of last zero and when a second zero appears,
shift the left pointer just after the previous zero to keep window valid.
Compute maximum window length and subtract one to account for deleting one element.
Time Complexity: O(n)
Space Complexity: O(1)
Where only constant extra space is used
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j = 0 , len = 0,count = 0;
        int zeropos = -1;
        while(j<n){
            int prev = zeropos;
            if(nums[j] == 0){
                count++;
                zeropos = j;
            }
            if(count <= 1)j++;
            else{
                len = max(len , j-i);
                i = prev + 1;
                count--;
                j++;
            }
        }
        if(zeropos == -1) return n-1;
        return max(len , j-i)-1;
    }
};