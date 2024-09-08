#include<bits/stdc++.h>
using namespace std;
// bool check(vector<int>arr,vector<int>v,int a, int b){
//     bool flag = true;
//     for(int i=0;i<a;i++){
//         if(arr[i]!=v[i])flag=false;
//     }
//     for(int i=arr.size()-1;i>(arr.size()-b-1);i--){
//         if(arr[i]!=v[i]) flag=false;
//     }
//     return flag;
// }
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        bool flag=false;
        if(n==a && n==b) flag=true;
        else if(n-a-b>1)flag=true;
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}