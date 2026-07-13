/*
Category: Heap, Priority Queue, Hash Map

Approach:
- Count the frequency of each word using a hash map.
- Maintain a min-heap of size k with a custom comparator that prioritizes lower frequencies and, for equal frequencies, lexicographically larger words for removal.
- Remove the top element whenever the heap size exceeds k to retain only the top k frequent words.
- Extract the heap contents and reverse the result to obtain the required ordering.

Time Complexity: O(n + m log k)
Space Complexity: O(m + k)
*/
class Solution {
public:
struct cmp{
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const{
        if(a.first != b.first) return a.first > b.first;
        else return a.second < b.second;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(string s : words) mp[s]++;
        priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> pq;
        for(auto x : mp){
            pq.push({x.second, x.first});
            if(pq.size() > k) pq.pop();
        }
        vector<string> ans;
        while(!pq.empty()) ans.push_back(pq.top().second), pq.pop();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};