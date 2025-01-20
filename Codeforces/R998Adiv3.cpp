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
        ll a[4];
        for(int i=0;i<4;i++){
            cin>>a[i];
        }
        ll x = a[0]+a[1];
        ll count=1,ans=0;
        // if(a[1]+x==a[2]) count++;
        if(a[1]+x==a[2])count++;
        if(x+a[2]==a[3])count++;
        ans=max(count,ans);
        count=0;
        x = a[3]-a[2];
        // if(a[1]+x==a[2]) count++;
        if(a[1]+x==a[2])count++;
        if(x+a[2]==a[3])count++;
        ans=max(ans,count);
        cout<<ans<<endl;
    }
}