/*
Category: Array (Primary)

Approach:
Place positive numbers at even indices and negative numbers
at odd indices using two pointers. Traverse once and fill
the result array accordingly.

Time Complexity: O(n)
Space Complexity: O(n)

Where n = number of elements.
*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int pos = 0 , neg = 1;
        for(int x : nums){
            if(x>=0){
                ans[pos] = x;
                pos +=2;
            }
            else{
                ans[neg] = x;
                neg +=2;
            }
        }
        return ans;
    }
};