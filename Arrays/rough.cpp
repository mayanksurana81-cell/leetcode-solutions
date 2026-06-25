#include<iostream>
#include<vector>
using namespace std;
void helper(int arr[], int n, int idx, vector<int>& v){
    if(idx >= n){
        for(int ele : v) cout<<ele<<" ";
        cout<<endl;
        return;
    }
    v.push_back(arr[idx]);
    helper(arr, n, idx + 1, v);
    v.pop_back();
    helper(arr,n,idx+1,v);    
}
int main(){
    int arr[5] = {1, 2, 3};
    vector<int> v;
    helper(arr, 3, 0, v);
}