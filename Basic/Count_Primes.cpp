 /*
Category: Mathematics, Sieve of Eratosthenes

Approach:
- Use the Sieve of Eratosthenes to identify all prime numbers less than n.
- Initially mark every number as prime.
- Starting from 2, for each prime number:
  - Mark all of its multiples beginning from i*i as non-prime.
  - Multiples smaller than i*i would already have been processed by smaller primes.
- After completing the sieve, count all numbers that remain marked as prime.
- Return the count of primes strictly less than n.

Time Complexity: O(n log log n)
Space Complexity: O(n)
 */
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<bool> prime(n,true);
        prime[0] = prime[1] = false;
        for(int i = 2; i*i <=n; i++){
            if(prime[i]){
                for(int j = i*i; j < n; j+=i) prime[j] = false;
            }
        }
        int count = 0;
        for(int i = 2; i < n; i++){
            if(prime[i]) count++;
        }
        return count;

    }
};