#include<bits/stdc++.h>
using namespace std;
bool ap(vector<int>v){
    if(v.size()==1)return true;
    int d=v[1]-v[0];
    for(int i=1;i<v.size();i++){
        if((v[i]-v[i-1])!=d) return false;
    }
    return true;
}
int ans1(vector<int>v){
    if(v.size()==1)return 0;
    return v[1]-v[0];
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    map<int,vector<int>>mpp;
    for(int i=0;i<n;i++){
        mpp[a[i]].push_back(i);
    }
    int count=0;
    map<int,int>ans;
    for(auto x : mpp){
        if(ap(x.second)){
            count++;
            ans[x.first]=ans1(x.second);
        }
    }
    cout<<count<<endl;
    for(auto x : ans){
        cout<<x.first<<" "<<x.second<<endl;
    }
}