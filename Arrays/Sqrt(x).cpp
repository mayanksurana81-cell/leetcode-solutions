/*
Category: Binary Search
Approach:
Apply binary search on range [0, x] to find the largest integer whose square
is less than or equal to x. Use long long to avoid overflow during multiplication.
Time Complexity: O(log x)
Space Complexity: O(1)
*/
class Solution {
public:
    int mySqrt(int x) {
        int lo = 0,hi = x;
        
        while(lo<=hi){
            long long mid = lo + (hi-lo)/2;
            if(mid*mid==x){
                return mid;
                
            }
            else if(mid*mid>x) hi = mid-1;
            else lo = mid +1;
        }
        return hi;
        
    }
};