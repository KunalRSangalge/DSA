#include<bits/stdc++.h>
using namespace std;
int f(int n,int k,int h[],vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1) return dp[n];

    int ans=INT_MAX;
    for(int i=1;i<=k;i++){
        int temp = INT_MAX;
        if((n-i)>=0) temp = abs(h[n]-h[n-i])+f(n-i,k,h,dp);
        ans = min(ans,temp);
    }
    return dp[n] = ans;

}
int main(){
    int n,k;
    cin>>n>>k;
    int h[n];
    for(int i=0;i<n;i++) cin>>h[i];
    vector<int>dp(n,-1);
    int ans = f(n-1,k,h,dp);
    cout<<ans<<endl;
}