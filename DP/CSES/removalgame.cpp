#include<bits/stdc++.h>
using namespace std; 
#define ll int64_t
ll f(int i,int j,int prev,ll a[],vector<vector<ll>>&dp){
    if(i==j){
        if(prev==0)return a[j];
        else return 0;
    }
    if(dp[i][j]!=LLONG_MIN)return dp[i][j];
    if(prev==0){
        return dp[i][j]=max(a[i]+f(i+1,j,1,a,dp),a[j]+f(i,j-1,1,a,dp));
    }
    else{
        return dp[i][j]=min(f(i+1,j,0,a,dp),f(i,j-1,0,a,dp));
    }
}
int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,LLONG_MIN));
    // cout<<f(0,n-1,0,a,dp);
    int prev=0;
    
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(prev==0){
                dp[i][j]=max(a[i]+dp[i+1][j],a[j]+dp[i][j-1]);
                prev=1;
            }
            else{
                dp[i][j]=min(dp[i+1][j],dp[i][j-1]);
                prev=0;
            }
        }
    }
}