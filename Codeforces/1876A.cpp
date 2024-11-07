#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,p;
        cin>>n>>p;
        ll a[n],b[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n;i++){
            cin>>b[i];
        }
        vector<pair<ll,ll>>v;
        for(ll i=0;i<n;i++)v.push_back(make_pair(a[i],b[i]));

        sort(v.begin(), v.end(), [](auto &left, auto &right) {
            return left.second < right.second;
        });
        ll ans=p;
        ll req=n-1;
        for(int i=0;i<n;i++){
            if(v[i].second>=p) break;
            ll curr=min(v[i].first,req);
            ans+=(v[i].second*curr);
            req-=curr;
            if(req==0) break;

        }
     ans+=(req*p);

        cout<<ans<<endl;

    }
}