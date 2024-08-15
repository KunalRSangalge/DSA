#include<bits/stdc++.h>
using namespace std;
//this is right but TLE
void solve(int a[],int n,int m,int sum,vector<int>&ans){
    if(n<0) return ;
    if(n==0){
        ans[0]=max(ans[0],sum);
        ans[1]=min(ans[1],sum);return;
    }
    for(int i=0;i<m;i++){
        if(a[i]>0){
        sum+=a[i];
        a[i]--;
        solve(a,n-1,m,sum,ans);
        a[i]++;
        sum-=a[i];}
    }

}
//This function does not take all cases
// void solve(int a[],int n,int m, int idx,int sum,vector<int>&ans){
//     //base case
//     if(n<0) return;
//     if(n==0){
//         ans[0]=max(ans[0],sum);
//         ans[1]=min(ans[1],sum);
//         return;
//     }
//     if(idx>=m){
//         return;
//     }
    
//         //include
//         if(a[idx]!=0){
//            // sum+=a[idx];
//           //  int t=a[idx];
//             a[idx]--;
//             solve(a,n-1,m,idx,sum+a[idx],ans);
//           //  sum-=t;
//             a[idx]++;
//         }
        
        
//         //exclude
//         solve(a,n,m,idx+1,sum,ans);   
// }
int main(){
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int i=0;i<m;i++)cin>>a[i];
    int sum=0;
    vector<int>ans;
    ans.push_back(0);
    ans.push_back(INT_MAX);
    //solve(a,n,m,0,sum,ans);
    solve(a,n,m,0,ans);
    cout<<ans[0]<<" "<<ans[1];
    
}