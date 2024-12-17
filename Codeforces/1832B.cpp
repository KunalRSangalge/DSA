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
        int n,k;
        cin>>n>>k;
        int a[n+1];
        for(int i=0; i<n ;i++) 
        {
            cin>>a[i];
        }
        ll maxi = 0;
        sort(a, a+n);
        ll sum = 0;
        ll b[n];
        for(int i=0; i<n; i++) 
        {
            sum += a[i];
            b[i+1] = b[i]+a[i];
        }
        for(int i=0; i<=k; i++) 
        {
            maxi = max(maxi, b[n-i]-b[2*(k-i)]);
        }
        cout<<maxi<<endl;
    }
}