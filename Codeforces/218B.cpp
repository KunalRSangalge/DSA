#include<bits/stdc++.h>
using namespace std;
void solve(int a[],int n,int m, int idx,int sum,vector<int>&ans){
   
    if(idx>=m){
        ans[0]=max(ans[0],sum);
        ans[1]=min(ans[1],sum);
        return;
    }
    for(int i=0;i<n;i++){
        //include
        if(a[i]!=0){
            sum+=a[i];
            a[i]--;
            solve(a,n,m,idx+1,sum,ans);
            sum-=a[i];
        }
        //exclude
        solve(a,n,m,idx+1,sum,ans);
                
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int i=0;i<m;i++)cin>>a[i];
    int sum=0;
    vector<int>ans;
    ans.push_back(0);
    ans.push_back(INT_MAX);
    solve(a,n,m,0,sum,ans);
    cout<<ans[0]<<" "<<ans[1];
    
}