 /*
Category: Binary Search on Answer, Greedy

Approach:
- The positions are first sorted so that balls can be placed greedily from left to right.
- Binary search is applied on the minimum possible distance between any two balls.
- For a candidate distance 'mid':
  - Start by placing the first ball at the first position.
  - Greedily place the next ball only when the distance from the previously placed ball is at least 'mid'.
  - If all m balls can be placed successfully, that distance is feasible.
- If a distance is feasible, try searching for a larger minimum distance.
- Otherwise reduce the search space.

Time Complexity: O(n log(maxDistance))
Space Complexity: O(1)

 */
class Solution {
public:
    bool isPossible(vector<int> &position , int mid , int m){
        int ball = 1;
        int pos = position[0];
        for(int i = 1 ; i<position.size() ; i++){
            if(position[i] - pos >= mid){
                ball++;
                pos = position[i];
            }
            if(ball == m) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin() , position.end());
        int s = 1 , e = position[n-1] - position[0];
        int ans = s;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(isPossible(position , mid , m)){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return ans;
    }
};