#include<bits/stdc++.h>
using namespace std;
bool notp(int a[],int j){
    int k=a[j];
    j--;
    while(j>=0){
        if(k==a[j]) return false;
        j--;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];

    int count=0;
    map<int,int>mpp;
for(int i=0;i<n;i++){
    int idx=i,d=0;
    bool flag=true;
    if(notp(a,i)){
        for(int j=i+1;j<n;j++){        
        if(a[i]==a[j]){
        if(d==0){
            d=j-i;
            idx=j;
        }
        else{
            if(d!=(j-idx)) flag=false;
            else{
                    idx=j;
                }
            }
        }
    
    }
        if(flag){count++;mpp[a[i]]=d;}
    }    
}
cout<<count<<endl;
for(auto x : mpp){
    cout<<x.first<<" "<<x.second<<endl;
}
}