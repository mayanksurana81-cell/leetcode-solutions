/*
Category: String (Primary), Heap/Priority Queue (Secondary)

Approach:
Count frequency of each character using a hashmap.
Push (frequency, character) pairs into a max heap.
Extract from heap and append characters frequency times
to build the string in decreasing frequency order.

Time Complexity: O(n log k)
Space Complexity: O(k)

Where n = length of the string,
      k = number of unique characters.
*/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char , int> mp;
        for(char ch : s){
            mp[ch]++;
        }
        priority_queue<pair<int,char>> q;
        for(auto &p : mp){
            q.push({p.second , p.first});
        }
        string ans = "";
        while(!q.empty()){
            pair<int,char> x;
            x = q.top();
            q.pop();
            ans += string(x.first , x.second);    
        }
        return ans;
    }
};