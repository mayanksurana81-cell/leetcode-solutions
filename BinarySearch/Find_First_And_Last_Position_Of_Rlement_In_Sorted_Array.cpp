/*
Category: Array (Primary), Binary Search (Secondary)

Approach:
Perform two binary searches: one to find the first occurrence
(lower bound) and one to find the last occurrence (upper bound)
of the target. Validate indices before returning.

Time Complexity: O(log n)
Space Complexity: O(1)

Where n = number of elements.
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return{-1,-1};
        int i = 0 , j = n-1;
        while(i<=j){
            int mid = i + (j-i)/2;
            if(nums[mid] < target) i = mid+1;
            else j = mid - 1;
        }
        int start = i;
        i = 0 , j = n-1;
        while(i<=j){
            int mid = i + (j-i)/2;
            if(nums[mid] <= target) i = mid+1;
            else j = mid - 1;
        }
        int end = j;
        if(start>end) return{-1,-1};
        return {start , end};
    }
};