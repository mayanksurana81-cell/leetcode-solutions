#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
int main(){
    unordered_set<int> st;
    unordered_map<int, int> mp;
    cout<<st.empty()<<" ";
    st.insert(1);
    st.insert(2);
    cout<<st.size()<<endl;
    cout<<mp.empty()<<" ";
    mp[1] = 10; 
    cout<<mp.size()<<endl;
    mp[1] = 20;
    cout<<mp[1];
    
}