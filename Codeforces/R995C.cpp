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
        ll n,m,k;
        cin>>n>>m>>k;
        ll a[m];
        for(ll i=0;i<m;i++){
            cin>>a[i];
        }
        ll b[k];
        for(ll i=0;i<k;i++){
            cin>>b[i];
        }

        if(k<(n-1)){
            for(int i=0;i<m;i++) cout<<0;
            cout<<endl;
        }
        else if(k==n-1){
            map<int,int>mpp;
            for(int i=0;i<k;i++) mpp[b[i]]++;
            for(int i=0;i<m;i++){
                if(mpp[a[i]]!=0) cout<<0;
                else cout<<1;
            }
            cout<<endl;
        }
        else{
            for(int i=0;i<m;i++){
                cout<<1;
            }
            cout<<endl;
        }
    }
}