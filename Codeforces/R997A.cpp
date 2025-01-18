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
        ll n,m;
        cin>>n>>m;
        ll x[n],y[n];
        ll xsum=0,ysum=0;
        for(ll i=0;i<n;i++){
            cin>>x[i]>>y[i];
            xsum+=x[i];
            ysum+=y[i];

        }
        // cout<<xsum<<ysum<<endl;
        ll ans = xsum*2+ysum*2+(m-x[0])*2+(m-y[0])*2;
        cout<<ans<<endl;
    }
}