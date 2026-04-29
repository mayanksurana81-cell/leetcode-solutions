/*
Category: Hashing / Brute Force
Approach:
Count frequency of digits, then iterate over all 3-digit even numbers (100–998).
For each number, check if its digits can be formed using available frequencies by temporarily reducing counts.
Time Complexity: O(1)
Space Complexity: O(1)
Where range of numbers is fixed (constant) and digit map size is limited
*/
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) {
        vector<int> ans;
        map<int,int> m;
        for(int ele : arr) m[ele]++;
        for(int i = 100 ; i <= 998 ; i+= 2){
            int x = i;
            int a = x%10; x/=10;
            int b = x%10; x/=10;
            int c = x;
            if(m.find(a)!=m.end()){
                m[a]--;
                if(m[a]==0) m.erase(a);
                if(m.find(b)!=m.end()){
                    m[b]--;
                    if(m[b]==0) m.erase(b);
                    if(m.find(c)!=m.end()) ans.push_back(i);
                    m[b]++;
                }
                m[a]++;
            }


        }
        return ans;
        
    }
};