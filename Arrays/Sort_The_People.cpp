 /*
Category: Arrays, Sorting

Approach:
- Pair each person's height with their corresponding name.
- Store these pairs in a vector where height is the primary sorting key.
- Sort the vector in descending order of height.
- Traverse the sorted pairs and extract the names into the answer vector.
- The resulting order of names matches the decreasing order of heights.

Time Complexity: O(n log n)
Space Complexity: O(n)
 */
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        vector<pair<int , string>> p;
        vector<string> ans;
        for(int i = 0 ; i<n ; i++){
            p.push_back({heights[i] , names[i]});
        }
        sort(p.rbegin() , p.rend());
        for(auto x : p){
            ans.push_back(x.second);
        }
        return ans;
    }
};