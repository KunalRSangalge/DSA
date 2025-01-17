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
        ll n,r;
        cin>>n>>r;
        ll a[n],sum=0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        int ans=0;
        if(r*2==sum){
            for(int i=0;i<n;i++){
                ans+=(a[i]/2)*2;
            }
        }
        else{
            int x=0;
            for(int i=0;i<n;i++){
                ans+=(a[i]/2)*2;
                r-=a[i]/2;
                if(a[i]%2!=0){
                    x++;
                }
            }
            if(r>=x)ans+=x;
            else{
                int remseat = r*2;
                while(remseat>x){
                    remseat-=2;
                    x--;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}