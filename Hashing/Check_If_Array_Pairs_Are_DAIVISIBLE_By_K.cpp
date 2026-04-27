/*
Category: Hashing
Approach:
Store frequency of remainders after normalizing elements with modulo k.
For valid pairing, count of remainder r must match count of k-r, and remainder 0 must have even count.
Time Complexity: O(n)
Space Complexity: O(n)
Where hashmap stores frequencies of remainders
*/
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int , int>mp;
        for(int ele : arr){
            ele = (((ele%k)+k)%k);
            mp[ele]++;
        }
        if(mp.find(0)!=mp.end()){
            if(mp[0]%2!=0) return false;
            mp.erase(0);
        }
        for(auto x : mp){
            int ele = x.first;
            int rem = k-ele;
            if(mp.find(rem)==mp.end()) return false;
            if(mp[rem] != mp[ele])return false;
        }
        return true;
        
    }
};