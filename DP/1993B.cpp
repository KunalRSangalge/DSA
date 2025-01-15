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
        vector<ll>odd,even;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            if(x%2==0)even.push_back(x);
            else odd.push_back(x);
        }
        if(odd.size()==n || even.size()==n){
            cout<<0<<endl;
            continue;
        }
        ll odmx = *max_element(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        ll ans=0;
        for(int i=0;i<even.size();i++){
            if(odmx>even[i]){
                odmx+=even[i];
                ans++;
            }
            else{
                ans+=(even.size()-i)+1;
                break;
            }
        }
        cout<<ans<<endl;
    }
}