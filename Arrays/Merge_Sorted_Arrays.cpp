/*
Category: Array (Primary), Two Pointers (Secondary)

Approach:
Use three pointers starting from the end of both arrays.
Compare elements and place the larger one at the end of nums1.
If nums2 has remaining elements, copy them to nums1.

Time Complexity: O(m + n)
Space Complexity: O(1)

Where m = size of nums1 elements,
      n = size of nums2.
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else if(nums1[i]<nums2[j]){
                nums1[k] = nums2[j];
                k--;
                j--;
            }
            else{
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
        if(i<0){
            while(j>=0){
            nums1[k] = nums2[j];
            k--;
            j--;
            }
        }
        
    }
};