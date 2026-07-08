/*
Category: Math (Primary)

Approach:
Extract digits using modulo and division.
Compute product and sum of digits simultaneously,
then return their difference.

Time Complexity: O(d)
Space Complexity: O(1)

Where d = number of digits.
*/
class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        while(n > 0){
            sum += n%10;
            product *= n%10;
            n = n/10;
        }
        return product - sum;
    }
};
