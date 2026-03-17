/*
Category: Array (Primary), Binary Search (Secondary)

Approach:
Apply binary search on a rotated sorted array with duplicates.
If duplicates block decision (nums[i] == nums[mid] == nums[j]),
shrink the range. Otherwise, identify the sorted half and
check if the target lies within it to decide direction.

Time Complexity: O(log n) average, O(n) worst case (due to duplicates)
Space Complexity: O(1)

Where n = number of elements.
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0 , j = n-1;
        while(i<=j){
            int mid = i + (j-i)/2;
            if(nums[mid] == target) return true;
            if(nums[i] == nums[mid] && nums[mid] == nums[j]){
                i++;
                j--;
                continue;
            }
            if(nums[i] <= nums[mid]){
                //left sorted
                if(nums[mid] > target && nums[i] <= target){
                    j = mid-1;
                }
                else i = mid+1;
            }
            else{
                //right sorted
                if(nums[j] >= target && nums[mid] < target){
                    i = mid+1;
                }
                else j = mid-1;
            }
        }
        return false;
    }
};