 /*
Category: Divide and Conquer, Sorting

Approach:
- Recursively divide the array into two halves until each subarray
  contains only one element.
- Since a single element is already sorted, start merging the subarrays.
- During merging:
  - Compare elements from both sorted halves.
  - Insert the smaller element into a temporary array.
  - After one half is exhausted, append the remaining elements
    from the other half.
- Copy the merged sorted elements back into the original array segment.
- Repeating this process for all levels produces a fully sorted array.

Time Complexity: O(n log n)
Space Complexity: O(n)
 */
class Solution {
public:
    void merge(vector<int>& nums, int lo, int mid, int hi){
        vector<int> res;
        int left = lo;
        int right = mid + 1;
        while(left <= mid && right <= hi){
            if(nums[left] <= nums[right]){
                res.push_back(nums[left]);
                left++;
            }
            else{
                res.push_back(nums[right]);
                right++;
            }
        }
            while(right <= hi){
                res.push_back(nums[right]);
                right++;
            }
            while(left <= mid){
                res.push_back(nums[left]);
                left++;
            }
        for(int i = lo; i <= hi; i++){
            nums[i] = res[i - lo];
        }
    }
 void mergesort(vector<int>& arr, int lo, int hi){
    if(lo >= hi) return;
    int mid = (lo + hi)/2;
    mergesort(arr, lo, mid);
    mergesort(arr, mid + 1, hi);
    merge(arr,lo,mid,hi);
 }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};