#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        char c;
        string s = "codeforces";
        cin>>c;
        bool flag=false;
        for(int i=0;i<s.size();i++){
            if(s[i]==c) {flag=true;
            break;}
        }
        if(flag) cout<<"yes"<<endl;
        else cout<<"NO"<<endl;
    }
}