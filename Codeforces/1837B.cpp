#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        int ans1=1,curr=1;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1])curr=1;
            else curr++;
            ans1=max(ans1,curr);
        }
        cout<<ans1+1<<endl;
    }
}