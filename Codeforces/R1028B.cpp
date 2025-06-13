#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>    
#include<ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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
const int maxi = 100000;

int main() {
    vector<long long> pow2(maxi + 1);
    pow2[0]=1;
    for (int i=1;i<=maxi;i++) {
        pow2[i] = (pow2[i-1]*2)%mod;
    }

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> p(n), q(n);
        for (int i=0;i<n;i++) {
            cin>>p[i];
        }
        for (int i=0;i<n; i++) {
            cin>>q[i];
        }

        ll maxA=-1, idxA=-1, maxB=-1, idxB=-1;
        vector<ll>r(n);

        for (int i=0;i<n; i++) {
            if (p[i] > maxA) {
                maxA=p[i];
                idxA=i;
            }
            if (q[i]>maxB) {
                maxB=q[i];
                idxB=i;
            }

            ll j1 = i-idxA;
            ll pa = maxA;
            ll pb = q[j1];

            ll j2 = i-idxB;
            ll p2a = p[j2];
            ll p2b = maxB;

            ll M1 = max(pa, pb);
            ll m1 = min(pa, pb);
            ll M2 = max(p2a, p2b);
            ll m2 = min(p2a, p2b);

            if (M1>M2) {
                r[i] = (pow2[pa] + pow2[pb]) % mod;
            } else if (M1 < M2) {
                r[i] = (pow2[p2a]+pow2[p2b]) % mod;
            } else {
                if (m1>=m2) {
                    r[i] = (pow2[pa]+pow2[pb]) % mod;
                } else {
                    r[i] = (pow2[p2a]+pow2[p2b]) % mod;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << r[i];
            if (i < n - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }
    return 0;
}
