#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> div(ll n){
    vector<ll>div;
    for(ll i=1;i<=sqrt(n);i++){
        if(n%i==0){
            div.push_back(i);
            div.push_back(n/i);
        }
    }
    return div;
}
void yes(){
    cout<<"YES"<<endl;
}
void no(){
    cout<<"NO"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k,q;
        cin>>n>>k>>q;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        vector<ll>v;
        ll cnt=0;
        // if(n==1){
        //     if(a[0]<=q){cout<<1<<endl; continue;}
        //     else {cout<<0<<endl; continue;}
        // }
        ll t=0;
        while(t<n){
            if(a[t]<=q){
                cnt++;
            }
            else{
                v.push_back(cnt);
                cnt=0;
            }
            t++;
        }
        v.push_back(cnt);
        // for(auto x : v){
        //     cout<<x<<" ";
        // }
        sort(v.rbegin(),v.rend());
        ll maxi = v[0];
        ll ans=0;
        if(v[0]==0) cout<<0<<endl;
        else{
            for(ll i=k-1;i<maxi;i++){
                for(ll j=0;j<v.size();j++){
                    if(v[j]>0){
                        if(v[j]-i>=0) ans+=v[j]-i;
                    }
                }
            }
            cout<<ans<<endl;
        }

    }
}