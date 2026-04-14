/*
Category: Prefix Sum / Difference Array
Approach:
Use a difference array to efficiently apply range updates for each booking.
Mark +seats at start index and -seats after end index, then compute prefix sum to get final seats per flight.
Time Complexity: O(n + m)
Space Complexity: O(n)
Where n is number of flights and m is number of bookings
*/
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> v(n + 2, 0);

        for(auto &x : bookings){
            int l = x[0], r = x[1], seats = x[2];
            v[l] += seats;
            v[r + 1] -= seats;
        }

        for(int i = 1; i <= n; i++){
            v[i] += v[i - 1];
        }

        vector<int> ans(n);
        for(int i = 1; i <= n; i++){
            ans[i - 1] = v[i];
        }

        return ans;
    }
};