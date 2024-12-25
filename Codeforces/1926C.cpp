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
int digsum(int n){
    int ans=0;
    while(n){
        ans += n%10;
        n/=10;
    }
    return ans;
}
ll f(int n, vector<ll>&dp){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int temp = digsum(n);
    return dp[n]=f(n-1,dp)+temp;
}
int main(){
    int t;
    cin>>t;
    int k = 200007;
    vector<ll>dp(k,-1);
    dp[0]=0;
    for(int i=1;i<=k;i++){
        dp[i]=dp[i-1]+digsum(i);
    }
    while(t--){
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
}