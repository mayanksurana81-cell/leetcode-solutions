 /*
Category: Binary Search on Answer

Approach:
- Binary search on the maximum number of products that can be assigned to a store.
- For a candidate value mid:
  - Compute how many stores are required if no store receives more than mid products.
  - For each product type, the required stores are ceil(quantity / mid).
- If the total required stores is less than or equal to n:
  - The distribution is feasible, so try a smaller maximum value.
- Otherwise:
  - Increase the allowed maximum value.
- The smallest feasible value obtained through binary search is the answer.

Time Complexity: O(m log M)
Space Complexity: O(1)
 */
class Solution {
    int getRetailer(vector<int>& arr , int qnt){
        int retail = 0;
        for(int i : arr){
            retail += int(ceil(double(i)/qnt));
        }
        return retail;
    }
public:
    int minimizedMaximum(int n, vector<int>& arr) {
        int low = 1 , high = 0;
        for(int i : arr){
            if(i > high) high = i;
        }
        while(low <= high){
            int mid = (low + high)/2;
            if(getRetailer(arr , mid) <= n){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};