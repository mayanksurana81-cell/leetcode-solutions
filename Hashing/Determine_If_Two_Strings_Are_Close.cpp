/*
Category: Hashing
Approach:
Check both strings have same set of characters using frequency maps.
Then compare frequency distributions by counting occurrences of each frequency to ensure transformability.
Time Complexity: O(n)
Space Complexity: O(1)
Where maps store at most 26 characters and their frequencies
*/
class Solution {
public:
    bool closeStrings(string str1, string str2) {
        if(str1.length()!=str2.length())return false;
        unordered_map<char,int>mp1,mp2;
        for(int i = 0 ; i<str1.length() ; i++){
            mp1[str1[i]]++;
            mp2[str2[i]]++;
        }
        for(auto x : mp1){
            char key = x.first;
            if(mp2.find(key)==mp2.end())return false;
        }
        unordered_map<int,int>h1,h2;
        for(auto x : mp1){
            int freq = x.second;
            h1[freq]++;
        }
        for(auto x : mp2){
            int freq = x.second;
            h2[freq]++;
        }
        for(auto x : h1){
            int key = x.first;
            if(h2.find(key)==h2.end())return false;
            if(h2[key]!=h1[key])return false;
        }
        return true;
        
    }
};