#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool check(vector<pair<ll,ll>>v){
    for(ll i=0;i<v.size();i++){
        if(v[i].second > 0) return true;
    }
    return false;
}
bool cmp(pair<ll,ll>&left , pair<ll,ll>&right){
    if(left.second == right.second){
        if(left.first < right.first) return true;
        else return false;
    }
    return left.second > right.second;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }

        vector<pair<ll,ll>>v;
        for(ll i=0; i<n; i++){
            v.push_back(make_pair(i+1,a[i]));
        }

        vector<ll>ans;
        while(check(v)){
            sort(v.begin(),v.end(),cmp);
            v[0].second -= k;
            if(v[0].second <= 0) ans.push_back(v[0].first);
        }
        for(auto x : ans){
            cout<<x<<" ";
        }
        cout<<endl;

    }
}