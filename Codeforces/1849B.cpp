#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool cmp(pair<ll,ll> &a,pair<ll,ll>&b){
    if(a.first==b.first) return a.second<b.second;
    return a.first>b.first;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<pair<ll,ll>>v;
        
        for(ll i=0;i<n;i++){
            ll in;
            cin>>in;

            if(in%k) in%=k;
            else in=k;
            v.push_back(make_pair(in,i+1));
        }

       sort(v.begin(),v.end(),cmp);
       for(int i=0;i<n;i++) cout<<v[i].second<<" ";
       cout<<endl;
    }
}