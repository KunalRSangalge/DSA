#include<bits/stdc++.h>
using namespace std;
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