 /*
Category: Mathematics

Approach:
- Trailing zeroes in n! are produced by factors of 10.
- Each factor of 10 consists of one 2 and one 5.
- Since factors of 2 are more abundant than factors of 5 in a factorial,
  the number of trailing zeroes is determined by the count of factor 5s.
- Count all multiples of 5, 25, 125, ... within n:
  - n/5 gives numbers contributing at least one factor of 5.
  - n/25 gives additional factors from multiples of 25.
  - Continue dividing by 5 until n becomes 0.
- Sum all contributions to obtain the number of trailing zeroes.

Time Complexity: O(log₅ n)
Space Complexity: O(1)
 */
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while(n > 0){
            n /= 5;
            count += n;
        }
        return count;
    }
};