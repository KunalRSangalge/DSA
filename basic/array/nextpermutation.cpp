#include<bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int>& nums) {
        int n=nums.size()-1;
        int i=n;
        while(i>0){
            if(nums[i]>nums[i-1]){
                swap(nums[i],nums[i-1]);
                if(i==1){
                    sort(nums.begin()+1,nums.end());
                }
                break;
            }
            
        }
        
    }
int main(){
    vector<int> arr={1,1,5};
    nextPermutation(arr);
    for(int i=0;i<arr.size();i++) cout<<arr[i];
}

//can use direct : next_permutation(nums.begin(),nums.end());