#include<iostream>
using namespace std;
int main(){
    int arr[] = {-3, 0, 2, -1, 5, 0, -4, 3};
    int n = 8;
    int pos = 0 , neg = 0 , zero = 0;
    for(int ele : arr){
        if(ele == 0) zero++;
        else if(ele > 0) pos++;
        else neg++;
    }
    cout<<pos<<" "<<neg<<" "<<zero;
}