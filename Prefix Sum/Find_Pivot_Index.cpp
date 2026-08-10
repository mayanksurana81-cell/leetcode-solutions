/*
Category: Array, Prefix Sum

Approach:
- Calculate the total sum of the array first.
- Traverse the array while maintaining the sum of elements from the left.
- Add the current element to left_sum and compare it with the remaining total_sum.
- If both are equal, the current index is the pivot index.
- Otherwise, subtract the current element from total_sum before moving to the next index, so total_sum represents the sum of elements to the right.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        int left_sum = 0;
        for(int ele : nums) total_sum += ele;
        for(int i = 0; i < n; i++){
            left_sum += nums[i];
            if(left_sum == total_sum) return i;
            else total_sum -= nums[i];
        }
        return -1;
    }
};