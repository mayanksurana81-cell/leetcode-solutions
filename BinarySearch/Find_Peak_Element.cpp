/*
Category: Array (Primary), Binary Search (Secondary)

Approach:
Use binary search to find a peak element. Compare mid with
mid+1: if nums[mid] > nums[mid+1], peak lies on left (including mid),
otherwise it lies on the right. Continue until convergence.

Time Complexity: O(log n)
Space Complexity: O(1)

Where n = number of elements.
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
            int n = nums.size();
            int i = 0 , j = n-1;
            while(i<j){
                int mid = i + (j-i)/2;
                if(nums[mid] > nums[mid+1]){
                    j = mid;
                }
                else{
                    i = mid+1;
                }
            }
    return i;
    }
};