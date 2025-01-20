#include<bits/stdc++.h>
#define ll long long 
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
        ll n;
        cin>>n;
        ll a[n],sum=0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        sort(a,a+n);
        if(n/2 == n-1){
            cout<<-1<<endl;
            continue;
        }
        ll avg = sum/n;
        ll t=n/2;
        // if(n%2)t=n/2;
        // else t=n/2+1;
        if(a[t]<(avg/2)){
            cout<<0<<endl;
            continue;
        }
        else{
            ll x = a[t]*2*n-sum+1;
            ll ans=max(0LL,x);
            cout<<ans<<endl;
        }
        
    }
}