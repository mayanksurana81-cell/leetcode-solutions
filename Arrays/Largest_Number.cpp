 /*
Category: Arrays, Sorting, Greedy

Approach:
- Convert the problem into arranging numbers in the best order.
- Sort the numbers using a custom comparator:
  - For two numbers a and b, compare:
    to_string(a) + to_string(b)
    and
    to_string(b) + to_string(a)
  - Place a before b if the first concatenation is larger.
- After sorting, concatenate all numbers to form the largest possible number.
- Handle the edge case where all numbers are zero by returning "0" instead of multiple leading zeros.

Time Complexity: O(n log n)
Space Complexity: O(n)
 */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(), nums.end(),
        [](int a , int b){
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        for(auto x : nums){
            ans += to_string(x);
        }
        if(ans[0] == '0') return "0";
        return ans;
    }
};