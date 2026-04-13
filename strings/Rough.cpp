#include<iostream>
#include<vector>
using namespace std;

 int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0 , j = n-1;
        while(i<=j){
            int mid = i + (j-i)/2;
            if(nums[mid] == target) return mid;
            if(nums[i] <= nums[mid]){
                if(nums[i] <= target && nums[mid] >= target){
                    j = mid-1;
                }
                else i = mid + 1;
            }
            else{
                if(nums[mid] <= target && nums[j] >= target){
                    i = mid+1;
                }
                else j = mid - 1;
            }
        
        
    }
    return -1;
}
int main(){
    vector<int> v = {4,5,0,1,4,4,4,4,4};
    cout<<search(v , 0);
    
}