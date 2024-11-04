#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n*k];
        for(ll i=0;i<n*k;i++){
            cin>>a[i];
        }
        ll med;
        if(n%2==0)med=n/2;
        else med=(n/2)+1;

        ll x = n*k;
        ll temp = k;
        ll ans = 0;
        while(k--){
            ans+=a[x - (n-med+1)];
            x-=(n-med+1);
        }
        cout<<ans<<endl;
    }
}