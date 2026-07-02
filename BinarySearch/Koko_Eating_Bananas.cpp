/*
Category: Array (Primary), Binary Search on Answer (Secondary)

Approach:
Binary search the minimum eating speed. For a candidate speed,
calculate total hours needed to finish all piles using ceil
division. If hours ≤ h, try a smaller speed; otherwise increase it.

Time Complexity: O(n log M)
Space Complexity: O(1)

Where n = number of piles,
      M = maximum bananas in a pile.
*/
class Solution {
public:
    long long CalHr(vector<int>& piles, int speed){
        long long hr = 0L;
        for(int i = 0 ; i<piles.size() ; i++){
            if(piles[i]%speed == 0){
                hr += piles[i]/speed;
            }
            else hr += (piles[i]/speed) +1;
        }
        return hr;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        int Max = INT_MIN;
        for(int ele : piles){
            if(ele>Max) Max = ele;
        }
        int i = 1 , j = Max;
        while(i<=j){
            int mid = i+(j-i)/2;
            long long hr = CalHr(piles , mid);
            if(hr<= h) j = mid - 1;
            else i = mid + 1;
        }
        return i;

    }
};
