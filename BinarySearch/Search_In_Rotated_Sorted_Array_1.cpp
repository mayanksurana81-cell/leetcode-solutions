/*
Category: Array (Primary), Binary Search (Secondary)

Approach:
Use binary search on a rotated sorted array. At each step,
identify the sorted half (left or right). Check if the target
lies within the sorted half to decide the search direction.

Time Complexity: O(log n)
Space Complexity: O(1)

Where n = number of elements.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 , high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;

            if(nums[low] <= nums[mid]){
                //sorted left
                if(nums[low] <= target && nums[mid] > target){
                    high = mid-1;
                }
                else low = mid+1;
            }
            else{
                //sorted right
                if(nums[mid] < target && nums[high] >= target) low = mid+1;
                else high = mid-1;

            }
        }
        return -1;
    }
};