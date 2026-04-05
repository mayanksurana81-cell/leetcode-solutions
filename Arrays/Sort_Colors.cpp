/*
Category: Array (Primary), Two Pointers / Dutch National Flag (Secondary)

Approach:
Use three pointers (lo, mid, hi) to partition array into
0s, 1s, and 2s. Swap elements to place them in correct region
in a single pass.

Time Complexity: O(n)
Space Complexity: O(1)

Where n = number of elements.
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int lo = 0 , mid = 0 , hi = n-1;
        while(mid<=hi){
            if(nums[mid] == 2){
                swap(nums[mid], nums[hi]);
                hi--;
            }
            else if(nums[mid] == 0){
                swap(nums[mid] , nums[lo]);
                lo++;
                mid++;
            }
            else mid++;
        }
    }
};