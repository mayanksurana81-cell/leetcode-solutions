/*
Category: Prefix Sum / Difference Array
Approach:
Use a difference array to mark passenger pickups and drop-offs at respective locations.
Convert it into prefix sum to get passengers at each point and check if it exceeds capacity.
Time Complexity: O(n + m)
Space Complexity: O(n)
Where n is max location value and m is number of trips
*/
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = 0;
        for(auto x : trips){
            n = max(n , x[2]);
        }
        vector<int> v(n+1 , 0);
        for(auto x : trips){
            v[x[1]] += x[0];
            v[x[2]] -= x[0]; 
        }
        int i = 0 , j = i+1;
        while(j<v.size()){
            v[j] += v[i];
            i++;
            j++;
        }
        for(int x : v){
            if(x > capacity) return false;
        }
        return true;
    }
};