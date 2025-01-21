#include<bits/stdc++.h>
#define ll int64_t
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
        ll a[n],even=0,odd=0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%2)odd++;
            else even++;
        }
        if(even==0){
            if(odd==1)cout<<0<<endl;
            else cout<<odd-1<<endl;
        }
        else{
            cout<<odd+1<<endl;
        }
        
    }
}