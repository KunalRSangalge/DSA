#include<bits/stdc++.h>
// #include "testlib.h"
using namespace std;
#define ll int64_t
bool check(vector<ll>a,ll mid,ll h){
    ll n = a.size();
    ll x=0;
    for(int i=1;i<n;i++){
        x += min(a[i]-a[i-1],mid);
    }
    return x+mid>=h;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        ll n,h;
        cin>>n>>h;
        vector<ll>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        ll low=1,high=1e18+1e10;
        ll ans=-1;
        while(low<high){
            ll mid = (high+low)/2;
            if(check(a,mid,h)){
                ans=mid;
                high=mid;
            }
            else low=mid+1;
        }
        cout<<ans<<endl;
    }
}