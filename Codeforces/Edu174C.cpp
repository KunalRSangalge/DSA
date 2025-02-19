#include<bits/stdc++.h>
using namespace std;
#define ll int64_t

//2312182 kunal
#define gc getchar_unlocked
#define fo(i,n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define si(x) cin>>x
#define pi(x) cout<<x<<endl
#define input(arr,n) fo(i,n) cin>>arr[i]
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pp;
#define ld long double
typedef vector<ll> vi;
typedef vector<pii> vpii;
typedef vector<pp> vpl;
typedef vector<vi> vvi;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
 int rng(int lim){
uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}
const ll mod =  998244353;
const ll N = 1e2+3,M=502;
const ll INF= 1LL*1001*1001*1001*1001*1001*1001 ;
ll power(ll x, ll y, ll M=mod)
{ if(x==0&&y==0) return 1;
    if (y == 0)
        return 1;

    ll p = power(x, y / 2, M) % M;
    p = (p * p) % M;

    return (y % 2 == 0) ? p : (x * p) % M;
}
 ll inverse(ll A, ll M)
{

    return power(A, M - 2, M);
    
}
ll mul(ll a,ll b){
    ll ans=1;
    ans=(ans*a)%mod;
    ans=(ans*b%mod)%mod;
    return ans;
}
ll divide(ll a,ll b){
    return mul(a,inverse(b,mod));
}
ll log(ll a,ll l){
    ll ans=0;
    ll curr=1;
    while(curr*a<=l){
        ans++;
        curr*=a;
    }
    return ans;
}
ll comp(ll n){
    return power(2,n)-1;
}
ll f(int i,int j,int prev,vector<ll>&a,vector<ll>&dp){
    if(i==a.size()){
        return 0;
    }
    if(dp[i]!=-1)return dp[i];
    ll pick1=0,np1=0,pick3=0,np3=0;
    if(prev==-1 && a[i]==1){
        pick1 = f(i+1,j,0,a,dp);
        np1 = f(i+1,j,prev,a,dp);
        return dp[i]=pick1+np1;
    }
    if(prev!=-1 && a[i]==2){
        return dp[i]=f(i+1,j+1,prev,a,dp);
    }
    if(prev!=-1 && a[i]==3){
        pick3 = (comp(j) + f(i+1,j,-1,a,dp));
        np3 = f(i+1,j,prev,a,dp);
        return dp[i]=pick3+np3;
    }
    return dp[i]=f(i+1,j,prev,a,dp);

}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>a(n);
        input(a,n);
        vector<ll>dp(4,0);
        ll ans=0;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                dp[1]++;
            }
            else if(a[i]==2){
                ll a = dp[2];
                dp[2]=(dp[1]+dp[2])%mod;
                dp[2]=(dp[2]+a)%mod;
            }
            else{
                ans = (ans+dp[2])%mod;
            }
            // cout<<dp[2]<<" ";
        }
        cout<<ans<<endl;
    }
}