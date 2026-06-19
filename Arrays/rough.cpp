#include<iostream>
#include<vector>
using namespace std;
void insertion_sort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j - 1]){
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
    
}
int main(){
    vector<int> arr = {5,2,3,1,-9,58,-89,-45,20,10};
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
    insertion_sort(arr);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}