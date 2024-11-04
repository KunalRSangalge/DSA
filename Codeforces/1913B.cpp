#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int c1=0,c0=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0') c0++;
            else c1++;
        }
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1' && c0>0) c0--;
            else if(s[i]=='0' && c1>0) c1--;
            else {
                ans=s.length()-i;
                break;
            }
        }
        cout<<ans<<endl;
    }
}