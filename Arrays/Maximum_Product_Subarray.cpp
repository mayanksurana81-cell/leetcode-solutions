 /*
Category: Arrays, Greedy

Approach:
- Traverse the array while maintaining:
  - mx = maximum product of a subarray ending at the current index.
  - mn = minimum product of a subarray ending at the current index.
- The minimum product is also tracked because multiplying a negative
  number can turn a small negative product into a large positive product.
- When a negative element is encountered, swap mx and mn before updating,
  since the signs of the products will reverse.
- For each element:
  - Start a new subarray from the current element.
  - Or extend the previous maximum/minimum product subarray.
- Update the answer using the current maximum product.
- The largest value obtained during the traversal is the maximum product
  subarray.

Time Complexity: O(n)
Space Complexity: O(1)
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long mx = INT32_MIN;
        long long mn = INT32_MAX;
        long long ans = INT_MIN;
        for(int ele : nums){
            if(ele <0) swap(mx,mn);
            mx = max((long long)ele,ele*mx);
            mn = min((long long)ele,ele*mn);
            ans = max(ans,mx);
        }
        return ans;

    }
};