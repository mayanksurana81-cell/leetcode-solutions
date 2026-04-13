/*
Category: Greedy / Two Pointers
Approach:
Sort people and pair the lightest with the heaviest if possible within limit, otherwise send the heaviest alone.
Use two pointers to minimize number of boats.
Time Complexity: O(n log n)
Space Complexity: O(1)
Where sorting dominates time and no extra space is used
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i = 0 , j = people.size()-1;
        int count = 0;
        sort(people.begin() , people.end());
        while(i<=j){
            if(people[i] + people[j] <= limit){
                i++;
                j--;
                count++;
            }
            else{
                count++;
                j--;
        }
        
    }
    return count;
    }
};