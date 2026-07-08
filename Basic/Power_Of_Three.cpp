 /*
Category: Mathematics

Approach:
- A power of 3 can be repeatedly divided by 3 until it becomes 1.
- If n is less than 1, it cannot be a power of 3.
- Continuously divide n by 3 while it is divisible by 3.
- After all possible divisions:
  - If n becomes 1, the original number was a power of 3.
  - Otherwise, it was not.

Time Complexity: O(log₃ n)
Space Complexity: O(1)
 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1) return false;
        while(n % 3 == 0){
            n /= 3;
        }
        return n == 1;
    }
};
