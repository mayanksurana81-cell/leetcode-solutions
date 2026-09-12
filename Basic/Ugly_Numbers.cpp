/*
Category: Math, Number Theory

Approach:
- Return false for non-positive numbers.
- Repeatedly divide n by 2, 3, and 5 until none of these factors remain.
- If the remaining value is 1, then n contains only the allowed prime factors 2, 3, and 5, so it is an ugly number.

Time Complexity: O(log n)
Space Complexity: O(1)
*/
class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;
        while(n%2 == 0) n /= 2;
        while(n % 3 == 0) n /= 3;
        while(n % 5 == 0) n /= 5;
        return n == 1;
    }
};