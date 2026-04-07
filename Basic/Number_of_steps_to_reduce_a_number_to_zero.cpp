/*
Category: Math (Primary), Simulation (Secondary)

Approach:
Repeatedly apply rules: if number is even, divide by 2;
if odd, subtract 1. Count steps until the number becomes zero.

Time Complexity: O(log n)
Space Complexity: O(1)

Where n = input number.
*/
class Solution {
public:
    int numberOfSteps(int n) {
        int steps = 0;
        while(n){
            if(n % 2 == 0){
                n /= 2;
                steps++;
            }
            else{
                n--;
                steps++;
            }
        }
        return steps;
    }
};