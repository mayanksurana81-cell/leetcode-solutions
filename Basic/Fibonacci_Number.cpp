/*
Category: Dynamic Programming (Iterative)
Approach:
Compute Fibonacci iteratively using two variables to store previous two values.
Update them in each iteration to build up to nth Fibonacci number without recursion.
Time Complexity: O(n)
Space Complexity: O(1)
Where only constant extra space is used
*/
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;

        int a = 0, b = 1;
        for(int i = 2; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};