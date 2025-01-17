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
ll f(ll i, ll j,ll x,vector<ll>&c,vector<ll>&h,vector<vector<ll>>&dp){
    if(i==c.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    
    
}
//memory limit exc
int main(){
    int t;
    cin>>t;
    while(t--){
        ll m,x;
        cin>>m>>x;
        vector<ll>c(m),h(m);
        ll sum=0;
        for(ll i=0;i<m;i++){
            cin>>c[i]>>h[i];
            sum+=h[i];
        }
        vector<vector<ll>>dp(m+1,vector<ll>(sum+1,1e15));
        for(int i=0;i<=m;i++) dp[i][0]=0;
        for(int i=0;i<m;i++){
            for(int j=1;j<=sum;j++){
                if(i-1>=0) dp[i][j]=min(dp[i-1][j],dp[i][j]);
                if(j-h[i]>=0){
                    ll cost=0;
                    if(i-1>=0) cost+=dp[i-1][j-h[i]];
                    if(cost+c[i]<=i*x){
                        dp[i][j]=min(dp[i][j],cost+c[i]);
                    }
                }
            }
        }
        ll ans=0;
        for(int i=0;i<=sum;i++){
            if(dp[m-1][i]<1e15){
                ans=i;
            }
        }
        cout<<ans<<endl;
    }
}