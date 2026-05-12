/*
Category: Backtracking / Recursion
Approach:
For every index, make two recursive choices:
exclude the current element from subset or include it.
When all elements are processed, store the constructed subset in the final answer.
Time Complexity: O(2^n * n)
Space Complexity: O(n)
Where recursion depth and temporary subset storage take linear space
*/
class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        if(k%2==0){
          int prevans = kthGrammar(n-1,k/2);
          if(prevans==0) return 1;
          else return 0;
        }
        else{
            int ans = kthGrammar(n-1,(k/2)+1);
            return ans;
        }
    }
};