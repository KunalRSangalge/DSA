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
        vector<ll>odd,even;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            if(i%2==0)even.push_back(x);
            else odd.push_back(x);
        }
        ll x=0,y=0;
        for(int i=0;i<even.size();i++){
            x = __gcd(x,even[i]);
        }
        for(int i=0;i<odd.size();i++){
            y = __gcd(y,odd[i]);
        }
        bool flag1=true,flag2=true;
        for(int i=0;i<even.size();i++){
            if(even[i]%y==0){
                flag1=false;
                break;
            }
        }
        for(int i=0;i<odd.size();i++){
            if(odd[i]%x==0){
                flag2=false;
                break;
            }
        }
        if(flag1)cout<<y<<endl;
        else if(flag2)cout<<x<<endl;
        else cout<<0<<endl;
    }
}