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
        ll n,a,b;
        cin>>n;
        ll c[n],d[n];
        for(ll i=0;i<n;i++){
            cin>>c[i];
        }
        for(ll i=0;i<n;i++){
            cin>>d[i];
        }
        ll p[n];
        for(ll i=0;i<n;i++){
            p[i]=c[i]-d[i];
        }
        ll count=0,idx=0;
        for(int i=0;i<n;i++){
            if(p[i]<0){
                count++;
                idx=i;
            }
        }
        if(count>1){
            no();
        }
        else if(count==0){
            yes();
        }
        else{
            bool flag=true;
            for(int i=0;i<n;i++){
                if(i!=idx){
                    if(p[i]<abs(p[idx])){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag)yes();
            else no();
        }
    }
}