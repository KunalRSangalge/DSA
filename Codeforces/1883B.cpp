#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        int count=0;
        for(auto it:mpp){
            if(it.second%2) count++;
        }
        if(n-k==0 || count>k+1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;  
    }
}