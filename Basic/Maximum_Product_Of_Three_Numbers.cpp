 /*
Category: Arrays, Greedy

Approach:
- Traverse the array once while tracking:
  - The three largest elements (max1, max2, max3).
  - The two smallest elements (min1, min2).
- The maximum product of three numbers can be formed in two ways:
  - Product of the three largest numbers.
  - Product of the two smallest (possibly negative) numbers and the largest number.
- Compute both products and return the larger one.

Time Complexity: O(n)
Space Complexity: O(1)
 */
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] > max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2){
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i] > max3) max3 = nums[i];
            if(nums[i] < min1){
                    min2 = min1;
                    min1 = nums[i];
                }
                else if(nums[i] < min2) min2 = nums[i];
        }
            long long product1 = 1LL*max1*max2*max3;
            long long product2 = 1LL*min1*min2*max1;
            return max(product1 , product2);
    }
};