#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
int f(int i,int j,int n,int m,string&s1,string&s2,vector<vector<int>>&dp){
    if(i==n)return m-j;
    if(j==m)return n-i;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j])return dp[i][j] = f(i+1,j+1,n,m,s1,s2,dp);
    else{
        int add = 1+f(i+1,j,n,m,s1,s2,dp);
        int rem = 1+f(i,j+1,n,m,s1,s2,dp);
        int rep = 1+f(i+1,j+1,n,m,s1,s2,dp);
        return dp[i][j] = min(add,min(rep,rem));
    }
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    // cout<<f(0,0,n,m,s1,s2,dp);
    for(int i=0;i<=m;i++)dp[n][i]=m-i;
    for(int i=0;i<=n;i++)dp[i][m]=n-i;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(s1[i]==s2[j])dp[i][j]=dp[i+1][j+1];
            else{
                dp[i][j]=min(1+dp[i+1][j],min(1+dp[i][j+1],1+dp[i+1][j+1]));
            }
        }
    }
    cout<<dp[0][0];
}