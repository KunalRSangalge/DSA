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
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        vector<bool>v(n+1,false);
        vector<int>b(n+1,0);

        for(int i=0;i<n;i++){
            if(v[a[i]]==false){
                b[i]=a[i];
                v[a[i]]=true;
            }
        }

        int k=1;
        for(int i=0;i<n;i++){
            if(b[i]==0){
                while(v[k]==true) k++;
                b[i]=k;
                v[k]=true;
            }
        }

        for(int i=0;i<n;i++){
            cout<<b[i]<<" ";
        }cout<<endl;
    }
}