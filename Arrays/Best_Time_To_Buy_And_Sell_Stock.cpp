/*
Category: Arrays (Two Pointers)

Approach:
We use two pointers to track the best day to buy and sell.
Pointer i represents the buying day, and j represents the selling day.

- If prices[j] < prices[i], we found a better buying day → update i = j
- Otherwise, calculate profit (prices[j] - prices[i]) and update maximum profit

This ensures we always buy at the lowest price before selling.

Time Complexity: O(n)
Space Complexity: O(1)

Where n = number of days (size of prices array)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 1;
        int n = prices.size();
        int sum = 0;
        while(j<n){
            int d = prices[j] - prices[i];
            if(d<0){
                i = j;
            }
            else{
                sum = max(sum,d);
            }
            j++;
        }
        return sum;
    }
};