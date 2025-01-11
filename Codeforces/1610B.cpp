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
bool checkpal(ll a[],int i,int j){
    ll n = sizeof(a)/sizeof(a[0]);
    while(i<j){
        if(a[i]!=a[j]) return false;
        i++;
        j--;
    }
    return true;
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
        if(checkpal(a,0,n-1)){
            yes();
            continue;
        }
        int i=0,j=n-1;
        while(i<j){
            if(a[i]!=a[j]){
                ll b[n];
                int l=0;
                for(int k=0;k<n;k++){
                    if(a[k]!=a[i]) b[l++]=a[k];
                }
                if(checkpal(b,0,l-1)){
                    yes();
                    break;
                }
                ll c[n];
                l=0;
                for(int k=0;k<n;k++){
                    if(a[k]!=a[j]) c[l++]=a[k];
                }
                if(checkpal(c,0,l-1)){
                    yes();
                    break;
                }
                else{
                    no();
                    break;
                }
            }
            i++;
            j--;
        }
        
    }
}