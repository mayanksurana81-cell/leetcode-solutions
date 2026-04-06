/*
Category: Math (Primary), Fast Exponentiation (Secondary)

Approach:
Even positions have 5 choices and odd positions have 4 choices.
Use modular exponentiation to compute (5^(ceil(n/2)) * 4^(floor(n/2))) % M.

Time Complexity: O(log n)
Space Complexity: O(log n)

Where n = length of the number.
*/
class Solution {
public:
    const int M = 1e9 + 7;
    long long power(long long a , long long b){
        if(b == 0) return 1;
        long long half = power(a,b/2);
        long long result = (half * half) % M;
        if(b %2 == 1) result = (result * a) % M;
        return result;
    }
    int countGoodNumbers(long long n) {
        return (long long) power(5,(n+1)/2) * power(4,n/2)%M;
    }
};