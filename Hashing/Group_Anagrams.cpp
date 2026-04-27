/*
Category: Hashing / Strings
Approach:
Sort each string to get its canonical form and use it as a key in hashmap.
Group all strings with same sorted form together to form anagrams.
Time Complexity: O(n * k log k)
Space Complexity: O(n * k)
Where n is number of strings and k is average string length
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        vector<vector<string>> ans;
        unordered_map<string ,vector<string>> mp;
        for(string str : arr){
            string lexo = str;
            sort(lexo.begin() , lexo.end());
            if(mp.find(lexo) == mp.end()){
                vector<string>s;
                s.push_back(str);
                mp[lexo] = s;
            }else{
                mp[lexo].push_back(str);
            }
        } 
        for(auto x : mp){
            ans.push_back(x.second);
        }
        return ans;
        
    }
};