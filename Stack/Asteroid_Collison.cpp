/*
Category: Stack, Simulation, Array

Approach:
- Process asteroids from left to right while using a vector as a stack to store surviving asteroids.
- Positive asteroids are pushed directly since they move to the right.
- When a negative asteroid is encountered, repeatedly remove smaller positive asteroids that collide with it.
- If an equal-sized positive asteroid exists, both are destroyed; otherwise, push the negative asteroid only if no positive asteroid remains to collide with it.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(asteroids[i] >= 0) ans.push_back(asteroids[i]);
            else{
                while(!ans.empty() && ans.back() > 0 && ans.back() < abs(asteroids[i])) ans.pop_back();
            if(!ans.empty() && ans.back() == abs(asteroids[i])) ans.pop_back();
            else if(ans.empty() || ans.back() < 0) ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};