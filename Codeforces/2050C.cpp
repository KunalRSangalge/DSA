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
ll digsum(ll n){
    ll ans=0;
    while(n){
        ans+=n%10;
        n/=10;
    }
    return ans;
}
ll countdig(ll n,ll p){
    ll ans=0;
    while(n){
        if(n%10 == p) ans++;
        n/=10;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll sum = digsum(n);
        ll count2 = countdig(n,2);
        ll count3 = countdig(n,3);
        ll ten =10;
        bool flag = false;
        for(int i=0;i<=min(ten,count2);i++){
            for(int j=0;j<=min(ten,count3);j++){
                if((sum+i*2+j*6) % 9 == 0) {
                    yes();
                    flag=true;
                    break;
                }
                if(flag) break;
            }
        }
        if(!flag) no();
    }
}