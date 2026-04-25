/*
Category: Math
Approach:
Reverse digits by extracting last digit and building the reversed number iteratively.
Handle negative numbers separately and check for overflow using long long before returning result.
Time Complexity: O(d)
Space Complexity: O(1)
Where d is number of digits in the integer
*/
class Solution {
public:
    int reverse(int x) {
        long long n = x;
        long long rev = 0;
        long long original = n;
        if(n<0) n = n*(-1);
        while(n>0){
            rev = rev * 10 + n%10;
            n = n/10;
        }
        if(rev>INT32_MAX) return 0;
        if(original > 0)return rev;
        else return rev*(-1);
        
    }
};