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
        ll n,x;
        cin>>n>>x;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll sm=0;
        for(ll i =0;i<n;i++)sm+=a[i];

        ll mini = 0;
        if(sm%x==0)mini=sm/x;
        else mini=sm/x + 1;

        ll maxi=0;
        for(ll i=0;i<n;i++){
            if(a[i]%x==0){
                maxi+=a[i]/x;
            }
            else{
                maxi+=a[i]/x+1;
            }
        }
        cout<<min(maxi,mini)<<" "<<max(maxi,mini)<<endl;
    }
}