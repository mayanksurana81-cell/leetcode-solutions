/*
Category: String / Recursion
Approach:
Recursively generate the previous term of the sequence, then build the current term
by counting consecutive identical characters and appending frequency followed by digit.
Time Complexity: O(2^n)
Space Complexity: O(n)
Where recursive calls build increasingly larger strings
*/
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string str = countAndSay(n-1);
        string ztr = "";
        int freq = 1;
        char ch = str[0];
        for(int i = 1 ; i<str.length() ; i++){
            char dh = str[i];
            if(ch==dh){
                freq++;
            }
            else{
                ztr += to_string(freq)+ch;
                freq = 1;
                ch = dh;
            }
        }
            ztr += to_string(freq)+ch;
            return ztr;

    }
};