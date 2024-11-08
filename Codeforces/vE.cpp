#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll sum=0,mini=INT32_MAX,neg=0;
        for(ll i=0;i<n;i++){
            sum+=abs(a[i]);
            if(a[i]<0)neg++;
            a[i]=abs(a[i]);
            mini=min(mini,a[i]);
        }
        if(neg%2!=0)cout<<sum-2*mini<<endl;
        else cout<<sum<<endl;
    }
}