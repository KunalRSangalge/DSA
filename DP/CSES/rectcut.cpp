#include<bits/stdc++.h>
using namespace std;
int f(int i,int j,vector<vector<int>>&dp){
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int hor=INT_MAX,ver=INT_MAX;
    for(int k=1;k<i;k++){
        hor=min(hor,f(k,j,dp)+f(i-k,j,dp)+1);
    }
    for(int k=1;k<j;k++){
        ver=min(ver,f(i,k,dp)+f(i,j-k,dp)+1);
    }
    return dp[i][j]=min(hor,ver);
}
int main(){
    int a,b;
    cin>>a>>b;
    vector<vector<int>>dp(a+1,vector<int>(b+1,INT_MAX));
    // cout<<f(a,b,dp);
    // for(int i=0;i<=min(a,b);i++)dp[i][i]=0;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j){dp[i][j]=0;continue;}
            int hor=INT_MAX,ver=INT_MAX;
            for(int k=1;k<i;k++){
                hor=min(hor,dp[k][j]+dp[i-k][j]+1);
            }
            for(int k=1;k<j;k++){
                ver=min(ver,dp[i][k]+dp[i][j-k]+1);
            }
            dp[i][j]=min(hor,ver);
        }
    }
    cout<<dp[a][b];
}