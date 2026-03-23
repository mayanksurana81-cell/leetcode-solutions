/*
Category: Array (Primary), Binary Search (Secondary)

Approach:
Apply binary search to find the target. If found, return index.
Otherwise, return the position where it would be inserted
to maintain sorted order (i pointer).

Time Complexity: O(log n)
Space Complexity: O(1)

Where n = number of elements.
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        while(i<=j){
            int mid = i + (j-i)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) i = mid+1;
            else j = mid-1; 
        }
        return i;
    }
};