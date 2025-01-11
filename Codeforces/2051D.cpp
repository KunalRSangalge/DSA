#include<bits/stdc++.h>
#define ll long long int
#define N 1e9
using namespace std;
#define N 1e9
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
int func(ll i ,ll n, ll a[],ll r){
    ll low=i+1,high=n-1;
    while(low<=high){
        ll mid = (low+high)/2;
        if(a[mid]<=r){
            low=mid+1;
        }
        else if(a[mid]>r){
            high=mid-1;
        }
    }
    return low-i;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        ll a[n];
        ll sum=0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        ll p = sum-y;
        ll q = sum-x;
        ll ans= 0;
        sort(a,a+n);
        for(int i=0;i<n;i++){
            ll r = p-a[i];
            ll s = q-a[i];
            ans += func(i,n,a,s) - func(i,n,a,r-1);
        }
        cout<<ans<<endl;
    }
}