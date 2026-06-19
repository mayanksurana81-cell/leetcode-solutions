#include<iostream>
#include<vector>
using namespace std;
void selection_sort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        int mini = i;
        for(int j = i; j <= n -1; j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[mini];
        arr[mini] = temp;
    }
}
int main(){
    vector<int> arr = {5,2,3,1};
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    selection_sort(arr);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}