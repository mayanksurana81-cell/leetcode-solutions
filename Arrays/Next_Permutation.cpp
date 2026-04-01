/*
Category: Array (Primary)

Approach:
Find the first decreasing element from the end (pivot).
Reverse the suffix after pivot, then swap pivot with the
next greater element to get the next lexicographical permutation.

Time Complexity: O(n)
Space Complexity: O(1)

Where n = number of elements.
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        int pivotidx = -1;
        //find pivot
        for(int i = n-1 ; i>0 ;i--){
            if(nums[i]>nums[i-1]){
                pivot = nums[i-1];
                pivotidx = i-1;
                break;
            }
        }
        if(pivot == -1){
            reverse(nums.begin() , nums.end());
            return;
        }
        // reverse pivot+1 to end and then swap
        reverse(nums.begin()+pivotidx+1 , nums.end());
        for(int i = pivotidx+1 ; i<n ; i++){
            if(nums[i]>pivot){
                swap(nums[pivotidx],nums[i]);
                return;
            }
        }

    }
};