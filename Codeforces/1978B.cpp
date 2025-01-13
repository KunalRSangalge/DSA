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
        ll n,a,b;
        cin>>n>>a>>b;
        ll k = min(b,n);
        if(a>b){
            cout<<n*a<<endl;
        }
        else{
            ll ans=0;
            if((b-a)>k){
                ll x = b-n;
                ans+=(b*(b+1))/2 - (x*(x+1))/2;
            }
            else{
                k=b-a;
                ll x = b-k;
                ans+=(b*(b+1))/2 - (x*(x+1))/2;
                ans+=a*(n-k);
            }
            cout<<ans<<endl;
        }
    }
}