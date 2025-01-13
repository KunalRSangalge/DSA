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
        sort(a,a+n);
        if(a[0]>=k){
            cout<<k<<endl;
            continue;
        }
        ll temp=a[0];
        ll press=0;
        for(int i=0;i<n;i++){
            if(i==0){
                if(a[i]*n >= k){
                    press+=k;
                    break;
                }
                k-=a[i]*n;
                press=a[i]*n+1;
            }
            else{
                if((a[i]-temp)*(n-i) >= k){
                    press+=k;
                    break;
                }
                else{
                    k-=(a[i]-temp)*(n-i);
                    press+=(a[i]-temp)*(n-i)+1;
                    temp=a[i];
                }
            }
        }
        cout<<press<<endl;
    }
}