/*
Category: Array (Primary), Binary Search (Secondary)

Approach:
Use binary search to find the minimum in a rotated sorted array.
Check which half is sorted: if left part is sorted, take nums[i]
as candidate and move right; otherwise take nums[mid] and move left.

Time Complexity: O(log n)
Space Complexity: O(1)

Where n = number of elements.
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans_min = INT_MAX;
        int i = 0, j = n-1;
        while(i<=j){
            if(nums[i] <= nums[j]) return min(ans_min , nums[i]);
            int mid = i + (j-i)/2;
            if(nums[i] <= nums[mid]){
                //left sorted
                ans_min = min(nums[i],ans_min);
                i = mid+1;
            }
            else{
                //right sorted
                ans_min = min(nums[mid],ans_min);
                j = mid-1;
            }
        }
        return ans_min;
    }
};
