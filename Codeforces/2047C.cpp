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
        ll n;
        cin>>n;
        ll a[2][n];
        for(ll i=0;i<2;i++){
            for(ll j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        // cout<<"ok"<<endl;
        ll ans=LLONG_MIN;
        for(int i=0;i<n;i++){
            ll curr=0;
            // cout<<curr<<endl;
            for(int j=0;j<n;j++){
                if(i==j){
                    curr+=(a[0][j]+a[1][j]);
                }
                else{
                    curr+=max(a[0][j],a[1][j]);
                }
            }
            ans=max(ans,curr);
        }
        cout<<ans<<endl;
    }
}