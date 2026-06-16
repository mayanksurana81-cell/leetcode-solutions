 /*
Category: Mathematics, Fast & Slow Pointers

Approach:
- Define a function that replaces a number with the sum of the squares
  of its digits.
- A happy number eventually reaches 1 after repeatedly applying this operation.
- Numbers that are not happy enter a cycle.
- Use Floyd's Cycle Detection algorithm:
  - slow moves one transformation at a time.
  - fast moves two transformations at a time.
- If fast reaches 1, the number is happy.
- If slow and fast meet at a value other than 1, a cycle exists and
  the number is not happy.

Time Complexity: O(log n)
Space Complexity: O(1)
 */
class Solution {
public:
int nextNum(int n){
    int sum = 0;
    while(n > 0){
        int d = n % 10;
        sum += d*d;
        n /= 10;
    }
    return sum;
}
    bool isHappy(int n) {
        int slow = n;
        int fast = nextNum(n);
        while(fast != 1 && slow != fast){
            slow = nextNum(slow);
            fast = nextNum(nextNum(fast));
        }
        return fast == 1;
    }
};