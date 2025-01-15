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
        int ind=0;
        map<int,int>mpp;
        for(int i=0;i<n;i++)mpp[a[i]]++;
        if(mpp[0]==n){
            cout<<0<<endl;
            continue;
        }
        else if(mpp[0]==0) cout<<1<<endl;
        else{
            int i=0;
            while(a[i]==0) i++;
            int j=i;
            while(j!=n && a[j]!=0) j++;
            // cout<<i<<j<<endl;
            if(mpp[0]==(n-(j-i))) cout<<1<<endl;
            else cout<<2<<endl;
        }
       
    }
}