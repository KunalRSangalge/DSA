#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool cmp(pair<ll,ll>& a, pair<ll,ll>& b){ 
    return a.second > b.second; 
} 
bool check(vector<pair<ll,ll>>v){
    for(int i=0;i<v.size();i++){
        if(v[i].second % 2 != 0) return false;
    }
    return true;
}
bool solve(vector<pair<ll,ll>>v){
    for(int i=0;i<v.size();i++){
        if(v[i].second != 1) return true;
    }
    return false;
}
ll see(ll n){
    ll ans=0;
    while(n%2==0){
        ans++;
        n/=2;
    }
    return ans;
}
int main(){
    
    ll n;
    cin>>n;
    map<ll,ll>mpp;
    
    while(n%2==0){
        n/=2;
        mpp[2]++;
    }
    for(ll i=3;i<sqrt(n);i++){
        while(n%i==0){
            mpp[i]++;
            n=n/i;
        }
    }
    if(n>2) mpp[n]++;

    vector<pair<ll,ll>>v;
    for(auto x : mpp){
        v.push_back(make_pair(x.first,x.second));
    }
    sort(v.begin(),v.end(),cmp);
    for(auto x: v){
        cout<<x.first<<" "<<x.second<<" ";
    }

    ll ans=0;
    while(solve(v)){
        if(check(v)){
            ll mini=INT32_MAX;
            for(auto x : v){
                mini=min(mini,see(x.second));
            }
            ans+=mini;
            for(auto x : v){
                x.second /= (2*mini);
            }
            cout<<ans<<" ";
        }
        else{
            ll maxi=INT32_MIN;
            for(auto x : v){
                if(x.second%2 != 0) maxi=max(maxi,x.second+1);
                else maxi = max(maxi,x.second);
            }
            ans++;
            ans+=maxi/2;
            break;
        }
    }
    ll op=1;
    for(auto x : v){
        op *= x.first;
    }
    cout<<op<<" "<<ans<<endl;
}