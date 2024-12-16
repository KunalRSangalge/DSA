#include<bits/stdc++.h>
#define ll long long int
#define N 1e9
using namespace std;
vector<bool>prime(N+1,true);
// O(NloglogN) sieve of erastosthanes
void p(){
    prime[0]=false;
    prime[1]=false;
    for(ll i=0;i<N;i++){
        if(prime[i]){
            for(ll j=2*i;j<N;j+=i){
                prime[j]=false;
            }
        }
    }
}
vector<ll> div(ll n){
    vector<ll>div;
    for(ll i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(i!=1)div.push_back(i);
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
ll check(ll a[],ll k,ll n){
    ll diff=0;
    ll maxa=-1e18,mina=1e18,suma=0;
    for(int i=0;i<n;i+=k){
        for(int j=i;j<i+k;j++){
            suma+=a[j];
        }
        maxa=max(maxa,suma);
        mina=min(mina,suma);
        suma=0;
    }
    diff = maxa-mina;
    return diff;
}
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
        vector<ll>v=div(n);
        ll ans=0;
        for(auto x : v){
            ll k = n/x;
            ans=max(ans,check(a,k,n));
        }
        cout<<ans<<endl;
    }
}