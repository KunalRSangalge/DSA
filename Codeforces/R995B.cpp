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
        ll n,a,b,c;
        cin>>n>>a>>b>>c;
        ll s = a+b+c;
        b+=a;
        c+=b;
        ll x = 0;
        if(n%s==0) x = n/s;
        else x = n/s + 1;
        a += (x-1)*s;
        b += (x-1)*s;
        c += (x-1)*s;
        if(n<=a) cout<<(1+3*(x-1))<<endl;
        else if(n<=b) cout<<(2+3*(x-1))<<endl;
        else if(n<=c) cout<<(3+3*(x-1))<<endl;
    }
}