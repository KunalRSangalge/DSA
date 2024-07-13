//checking which part is sorted and then eliminating that part if target not present
//O(logn)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int s=0,e=n,mid;
        while(s<=e){
            mid=(s+e)/2;
            if(nums[mid]==target)
            return mid;

            if(nums[mid] >= nums[s]){
                if(target <= nums[mid] && target >= nums[s])
                e=mid-1;
                else
                s=mid+1;
            }
            else{
                if(target >= nums[mid] && target <= nums[e])
                s=mid+1;
                else
                e=mid-1;
            }
        }
        return -1;
    }
};