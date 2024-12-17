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
        ll k,l1,r1,l2,r2;
        cin>>k>>l1>>r1>>l2>>r2;
        ll n=0;
        ll ans=0;
        while((r2>=(pow(k,n)*l1))){
            ll power = pow(k,n);
            ll a = (l2-power+1)/power;
            a = max(a,l1);

            ll b = r2/power;
            b = min(b,r1);

            ll t=0;
            ans+=max(t,(b-a+1));
            
            n++;
        }
        cout<<ans<<endl;
    }
}