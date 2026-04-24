/*
Category: Sliding Window
Approach:
Maintain a window with product less than k by expanding right pointer and shrinking from left when product exceeds k.
For each valid window, count number of subarrays ending at current index by adding window size.
Final cleanup loop accounts for remaining valid subarrays after traversal.
Time Complexity: O(n)
Space Complexity: O(1)
Where only constant extra space is used
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= 1) return 0;
        int count = 0;
        int product = 1;
        int i = 0 , j = 0;
        while(j<n){
            product *= nums[j];
            while(product >= k){
                count += j-i;
                product /= nums[i];
                i++;
            }
            j++;
        }
        while(i<n){
            count += j-i;
            product /= nums[i];
            i++;
        }
        return count;
    }
};