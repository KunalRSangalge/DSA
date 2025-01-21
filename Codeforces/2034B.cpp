#include<bits/stdc++.h>
#define ll int64_t
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
        ll n,m,k;
        cin>>n>>m>>k;
        string s;
        cin>>s;
        ll cnt=0,ans=0;
        bool flag=true;
        int i=0;
        while(i<n){
            if(s[i]=='0')cnt++;
            else cnt=0;
            if(cnt==m){
                cnt=0;
                ans++;
                i+=k;
            }
            else i++;
        }
        cout<<ans<<endl;
    }
}