//finding pivot and then getting answer 
//failed test case: nums=[3,1]
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1, mid, p;
        while (s < e) {
            mid = (s + e) / 2;

            if (nums[mid] > nums[0])
                s = mid + 1;
            else
                e = mid;
        }
        p = s;
        s = 0, e = nums.size() - 1;

        if (target >= nums[p] && target <= (nums[nums.size()-1])) {
            s = p;
            while (s <= e) {
                mid = (s + e) / 2;

                if (target == nums[mid])
                    return mid;
                else if (target > nums[mid])
                    s = mid + 1;
                else
                    e = mid - 1;
            }
        } else {
            e = p;
            while (s <= e) {
                mid = (s + e) / 2;

                if (target == nums[mid])
                    return mid;
                else if (target > nums[mid])
                    s = mid + 1;
                else
                    e = mid - 1;
            }
        }
        return -1;
    }
};