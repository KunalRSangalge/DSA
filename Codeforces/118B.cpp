#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int j=0;
    for(int i=0;i<=n;i++){
        for(int j=n-i;j>0;j--){
            cout<<" "<<" ";
        }
        if(i==0)
        cout<<"0";
        else
        cout<<"0 ";
        int k=1;
        for(;k<=i;k++){
            cout<<k;
            cout<<" ";
        }
        int l=k-2;
        for(;l>0;l--){
            cout<<l;
            cout<<" ";
        }
        if(i!=0)
        cout<<"0";
        cout<<endl;
    }
    
    for(int i=n;i>0;i--){
        // cout<<" "<<" ";
        for(int j=n-i;j>=0;j--){
            cout<<" "<<" ";
        }
        if(i==1)
        cout<<"0";
        else
        cout<<"0 ";
        int k=1;
        for(;k<i;k++){
            cout<<k;
            cout<<" ";
        }
        int l=k-2;
        for(;l>0;l--){
            cout<<l;
            cout<<" ";
        }
        if(i!=1)
        cout<<"0";
        cout<<endl;
    }
}