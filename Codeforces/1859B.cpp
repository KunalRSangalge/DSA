#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool cmp(pair<ll,ll>&left, pair<ll,ll>&right){
    return left.second < right.second;    
}
ll mini(ll a[], ll n){
    sort(a,a+n);
    return a[0];
}
ll secmini(ll a[], ll n){
    sort(a,a+n);
    return a[1];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll k=n;
        vector<pair<ll,ll>>v;
        while(k--){
            ll m;
            cin>>m;
            ll b[m];
            for(ll i=0;i<m;i++){
                cin>>b[i];
            }
            ll x = mini(b,m);
            ll y = secmini(b,m);
            v.push_back(make_pair(x,y));
        }

        ll mini=INT32_MAX;
        for(auto x : v){
            mini=min(mini,x.first);
        }

        sort(v.rbegin(),v.rend(),cmp);
        ll ans=mini;
        n--;
        for(auto x : v){
            if(n==0)break;
            ans+=x.second;
            n--;
        }
        cout<<ans<<endl;
    }
}