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
        int a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        int mn=min(0,a[0]),ans=a[0],sum=a[0];
        for(int i=1;i<n;i++){
            if(abs(a[i-1]%2)==abs(a[i]%2)){
                mn=0;
                sum=0;
            }
                sum+=a[i];
                ans=max(ans,sum-mn);
                mn=min(mn,sum);
            
        }
        cout<<ans<<endl;
}
}