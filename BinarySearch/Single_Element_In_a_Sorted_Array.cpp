/*
Category: Array (Primary), Binary Search (Secondary)

Approach:
Use binary search on index parity. In a sorted array, pairs
occupy (even, odd) indices. If this pattern breaks at mid,
the single element lies on the left; otherwise on the right.

Time Complexity: O(log n)
Space Complexity: O(1)

Where n = number of elements.
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int i = 0 , j = n-1;
        while(i<=j){
            int mid = i+ (j-i)/2;
            if(mid==0){
                if(nums[mid] != nums[mid+1]) return nums[mid];
                else i = mid+1;
            }
           else if(mid == n-1){
                if(nums[mid] != nums[n-2]) return nums[mid];
                else j = mid-1;
            }
           else if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
          else if(mid%2==0){
                if(nums[mid] == nums[mid+1]){
                    i = mid+1;
                }
                else j = mid-1;
            }
            else{
                if(nums[mid] == nums[mid-1]) i = mid+1;
                else j = mid-1;
            }
        }
            return 0;
    }
};