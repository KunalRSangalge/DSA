#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<cstdio>
using namespace __gnu_pbds;
using namespace std;
#define ll int64_t
typedef tree<ll, null_type, less_equal<ll>,
            rb_tree_tag,
            tree_order_statistics_node_update>
            ordered_set;

//2314169
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
typedef vector<vvi> vvvi;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b){ return (a/gcd(a,b))*b;}
void yes() { cout<<"Yes\n"; }
void no() { cout<<"No\n"; }
int rng(int lim){
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}
const ll mod =998244353;
const ll N = 1e7+3,M=502;
const ll inf= 1LL*1001*1001*1001*1001*1001*1001 ;
const ld check=0.29289321881;
//=======================
void myerase(ordered_set &t, int v){
    int rank = t.order_of_key(v);//Number of elements that are less than v in t
    ordered_set::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}
ll power(ll x, ll y, ll M=mod){
if(x==0&&y==0) return 1;
    if (y == 0)
        return 1;

    ll p = power(x, y / 2, M) % M;
    p = (p * p) % M;

    return (y % 2 == 0) ? p : (x * p) % M;
}
ll inverse(ll A, ll M){return power(A, M - 2, M);}
ll mul(ll a,ll b){
    ll ans=1ll;
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

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
      ll n,m,d;
      cin>>n>>m>>d;
      vector<string>a(n);
      input(a,n);
      vector<ll>dp(m+2,0),currdp(m+2,0);
      for(int i=0;i<m;i++) if(a[n-1][i]=='X'){
        currdp[i+1]=1;
      }
      for(int i=1;i<=m;i++){
        ll left=max(0,i-d);
        dp[left]+=currdp[i];
       ll right=min(m+1,i+d+1);
       dp[right]=(dp[right]+mod-currdp[i])%mod;
      }
      for(int i=1;i<=m+1;i++){
        dp[i]+=dp[i-1];
        dp[i]%=mod;
      }
      vector<ll>pdp(m+2);
      for(int i=1;i<=m+1;i++){
        pdp[i]+=pdp[i-1];
        if(a[n-1][i-1]=='X') pdp[i]+=dp[i];
        pdp[i]%=mod;
      }
      for(int i=n-2;i>=0;i--){
        vector<ll>ndp(m+2,0),predp(m+2,0);
        for(int j=1;j<=m;j++){
            if(a[i][j-1]=='X'){
                ll curr=sqrt(d*d-1);
                ndp[j]=(ndp[j]+(pdp[min(m,j+curr)]-pdp[max(0,j-curr-1)])+mod)%mod;

            }
        }
        for(int j=1;j<=m;j++){
            ll left=max(0,j-d);
            ll right=min(m+1,j+d+1);
            predp[left]+=ndp[j];
            predp[left]%=mod;
            predp[right]=(predp[right]-ndp[j]+mod)%mod;

        }
        for(int j=1;j<=m;j++){
            predp[j]=(predp[j]+predp[j-1])%mod;
        }
        for(int j=1;j<=m;j++){
            pdp[j]=pdp[j-1];
            if(a[i][j-1]=='X'){
                pdp[j]=(pdp[j]+predp[j])%mod;
            }
        }
        
      }
      cout<<pdp[m]%mod<<endl;


    }
}