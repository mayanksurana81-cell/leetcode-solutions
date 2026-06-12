 /*
Category: Bit Manipulation

Approach:
- Store all possible prime counts of set bits in a lookup set.
- Iterate through every number in the range [left, right].
- For each number:
  - Count its set bits using __builtin_popcount().
  - Check whether the count is prime by looking it up in the set.
- Increment the answer whenever the set-bit count is prime.
- Return the total count of such numbers.

Time Complexity: O(right - left + 1)
Space Complexity: O(1)
 */
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        set<int> s;
        s.insert(2);
        s.insert(3);
        s.insert(5);
        s.insert(7);
        s.insert(11);
        s.insert(13);
        s.insert(17);
        s.insert(19);
        int ans = 0;
        for(int i = left; i <= right ; i++){
            int x = __builtin_popcount(i);
            if(s.find(x) != s.end()) ans++;
        }
        return ans;
    }
};