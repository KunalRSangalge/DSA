#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        int c=0,c1=0,c0=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')c0++;
            else c1++;
        }
        c=min(c1,c0);
        if(c%2==0)cout<<"NET"<<endl;
        else cout<<"DA"<<endl;
    }
}