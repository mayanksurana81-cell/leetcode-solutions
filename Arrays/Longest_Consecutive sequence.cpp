/*
Category: Array (Primary), Set (Secondary)

Approach:
Insert elements into a set to remove duplicates and sort them.
Traverse the set and count consecutive sequences by checking
difference between adjacent elements.

Time Complexity: O(n log n)
Space Complexity: O(n)

Where n = number of elements.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size()==1) return 1;
        set<int> s;
        for(int ele : nums){
            s.insert(ele);
        }
        int count1 = 0 , count2 = 0;
        auto it = s.begin();
        int prev = *it;
        ++it;
        for(; it != s.end() ; ++it){
            if(*it-prev == 1) count1++;
            else{
                count2 = max(count1,count2);
                count1 = 0;
            }
            prev = *it;
        }
        int ans = max(count1 , count2);
        return ans+1;
    }
};