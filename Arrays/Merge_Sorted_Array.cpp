/*
Category: Two Pointers
Approach:
Use three pointers starting from the end of both arrays and merge in reverse order into nums1.
Compare elements from nums1 and nums2, placing the larger one at the end, and handle remaining elements.
Time Complexity: O(m + n)
Space Complexity: O(1)
Where merging is done in-place without extra space
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