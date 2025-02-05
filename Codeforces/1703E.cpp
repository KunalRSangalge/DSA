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


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<vector<ll>>a(n,vector<ll>(n));
        vector<vector<vector<ll>>>c;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
                // c[i][j].push_back(a[i][j]);
            }
        }
        c.push_back(a);
        if(n%2==0){
            ll p=0,q=0;
            for(int j=n-1;j>=0;j--){
                for(int i=0;i<n;i++){
                    c[p][q++].push_back(a[i][j]);
                }
                p++;
            }
            p=0,q=0;
            for(int i=n-1;i>=0;i--){
                for(int j=n-1;j>=0;j--){
                    c[p][q++].push_back(a[i][j]);
                }
                p++;
            }
            p=0,q=0;
            for(int j=0;j<n;j++){
                for(int i=n-1;i>=0;i--){
                    c[p][q++].push_back(a[i][j]);
                }
                p++;
            }
        }
        else{
            ll p=0,q=0;
            for(int j=n-1;j>=0;j--){
                for(int i=0;i<n;i++){
                    if(i!=n/2 && j!=n/2) c[p][q++].push_back(a[i][j]);
                }
                p++;
            }
            p=0,q=0;
            for(int i=n-1;i>=0;i--){
                for(int j=n-1;j>=0;j--){
                    if(i!=n/2 && j!=n/2) c[p][q++].push_back(a[i][j]);
                }
                p++;
            }
            p=0,q=0;
            for(int j=0;j<n;j++){
                for(int i=n-1;i>=0;i--){
                    if(i!=n/2 && j!=n/2) c[p][q++].push_back(a[i][j]);
                }
                p++;
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                map<ll,ll>mpp;
                for(int k=0;k<c[i][j].size();k++){
                    mpp[c[i][j][k]]++;
                }
                ans+=min(mpp[0],mpp[1]);
            }
        }
        cout<<ans<<endl;
    }
}
