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
        ll n,k;
        cin>>n>>k;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll x = a[k-1],y=0,yidx=0;
        ll wins=0;
        for(ll i=0;i<n;i++){
            if(a[i]>x){
                y=a[i];
                yidx=i;
                break;
            }
        }
        if(y==0){
            cout<<n-1<<endl;
            continue;
        }
        if(yidx>k-1){
            cout<<yidx-1<<endl;
            continue;
        }
        else{
            wins=yidx-1;
            if(yidx==0)wins=0;

            swap(a[k-1],a[yidx]);
            ll nyidx=0;;
            for(int i=yidx;i<n;i++){
                if(a[i]>x){
                    nyidx=i;
                    break;
                }
            }
            if(yidx==0){
                wins = max(wins,nyidx-1);
            }
            else{
                wins = max(wins,nyidx-yidx);
            }
        }
        cout<<wins<<endl;
    }
}