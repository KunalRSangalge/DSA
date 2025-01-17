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
ll lcm(ll a,ll b){
    ll gcd = __gcd(a,b);
    return (a*b)/gcd;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        ll nx = n/x;
        ll ny = n/y;
        ll z = lcm(x,y);
        ll nz = n/z;

        ll p = n-nx+nz;
        ll sumx = (n*(n+1))/2 - (p*(p+1))/2;

        ll q = ny-nz;
        ll sumy = (q*(q+1))/2;

        cout<<sumx-sumy<<endl;
    }
}