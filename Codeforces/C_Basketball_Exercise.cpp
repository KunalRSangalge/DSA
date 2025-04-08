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
const ll mod =  1e9+7;
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

ll f(ll x,vector<ll>&r1,vector<ll>&r2,ll i,ll j,vector<vector<ll>>&dp){
    if(i==r1.size())return x;
    if(dp[i][j]!=-1)return dp[i][j];
    if(j==0){
        return dp[i][j]=max(r2[i]+f(x,r1,r2,i+1,1,dp),f(x,r1,r2,i+1,0,dp));
    }
    else return dp[i][j]=max(r1[i]+f(x,r1,r2,i+1,0,dp),f(x,r1,r2,i+1,1,dp));
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> r1(n),r2(n);
        input(r1,n);
        input(r2,n);
        // vector<vector<ll>>dp(n,vector<ll>(3,0));
        // dp[0][0]=r1[0];
        // dp[0][1]=r2[0];
        // dp[0][2]=0;
        // for(int i=1;i<n;i++){
        //     dp[i][0]=max(dp[i-1][1]+r1[i],max(dp[i-1][2]+r1[i],r1[i]));
        //     dp[i][1]=max(dp[i-1][0]+r2[i],max(dp[i-1][2]+r2[i],r2[i]));
        //     dp[i][2]=max(dp[i-1][0],dp[i-1][1]);
        // }        
        // cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<endl;
        vector<vector<ll>>dp(n,vector<ll>(2,-1));
        ll ans = f(r1[0],r1,r2,1,0,dp);
        vector<vector<ll>>dp2(n,vector<ll>(2,-1));
        ans = max(ans,f(r2[0],r1,r2,1,1,dp2));
        cout<<ans<<endl;
    }
}
