//TLE using O(N*Q)
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
        ll n,q;
        cin>>n>>q;
        ll a[n],x[q];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<q;i++){
            cin>>x[i];
        }
        for(int i=0;i<q;i++){
            for(int j=0;j<n;j++){
                ll p=pow(2,x[i]);
                if(a[j]%p==0){
                    ll r = pow(2,x[i]-1);
                    a[j]+=r;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }cout<<endl;
    }
}