//number of LIS
//here dp[i] is length of LIS ending at i upto i
//and cnt[i] is number of LIS ending at i upto i
//everytime you find a arr[i]>arr[j] && dp[j]+1 > dp[i] then you update dp[i]=dp[j]+1 which means you find longer subsequence
//change is you update cnt[i] = cnt[j] which means you find LIS ending at i
//if you find arr[i]>arr[j] && dp[j]+1 == dp[i] then you update cnt[i]+=cnt[j] which means you find another LIS ending at i

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j] < arr[i] && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    cnt[i]=cnt[j];
                }
                else if(arr[j]<arr[i] && dp[i]==dp[j]+1){
                    cnt[i]+=cnt[j];
                }
            }
        }
        int maxi = *max_element(dp.begin(),dp.end());
        int ans= 0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi)ans+=cnt[i];
        }
        return ans;
    }
};