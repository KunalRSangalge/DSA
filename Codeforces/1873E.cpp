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
        ll maxi = 0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            maxi=max(maxi,a[i]);
        }
        sort(a,a+n);
        if(n==1){
            cout<<a[0]+x<<endl;
            continue;
        }
        ll h = a[0];
        for(int i=0;i<n-1;i++){
            if((i+1)*(a[i+1]-a[i])>x){
                h+=x/(i+1);
                break;
            }
            else{
                h+=(a[i+1]-a[i]);
                x-=(i+1)*(a[i+1]-a[i]);
            }
            if(h>=maxi){
                h+=x/n;
                break;
            }
        }
        cout<<h<<endl;
    }
}