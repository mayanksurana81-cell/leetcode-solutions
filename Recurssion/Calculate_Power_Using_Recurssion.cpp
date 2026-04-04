/*
Category: Recursion (Primary), Divide and Conquer (Secondary)

Approach:
Use fast exponentiation. Recursively compute power by
dividing exponent by 2. If exponent is even, square the base;
if odd, multiply once more. Handle negative exponent separately.

Time Complexity: O(log n)
Space Complexity: O(log n)

Where n = absolute value of exponent.
*/
class Solution {
public:
    double helper(double x , long long n){
        if(n == 0) return 1;

        else if(n == 1) return x;

        if(n%2 == 0) return helper(x*x , n/2);

        return x * helper(x , n-1);
    }
    double myPow(double x, int n) {
        long long N = n;
        if(N < 0) return double(1.0) / helper(x , -1 * N);
        return helper(x , N);
    }
};