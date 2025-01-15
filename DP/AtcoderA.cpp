#include<bits/stdc++.h>
using namespace std;
int f(int n,int h[],vector<int>&dp){
    if(n<0) return 0;
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1) return dp[n];

    int step1 = abs(h[n]-h[n-1])+f(n-1,h,dp);
    int step2 = 1e8;
    if(n>=2) step2=abs(h[n]-h[n-2])+f(n-2,h,dp);

    return dp[n] = min(step1,step2);
}
int main(){
    int n;
    cin>>n;
    int h[n];
    for(int i=0;i<n;i++) cin>>h[i];
    vector<int>dp(n,-1);
    int ans = f(n-1,h,dp);
    cout<<ans<<endl;
}