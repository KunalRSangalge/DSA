#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        int i=0,j=n-1;
        ll ans=n;
        while(s[i]!=s[j] && i<j){
            ans-=2;
            i++;
            j--;
        }
        cout<<ans<<endl;
    }
}