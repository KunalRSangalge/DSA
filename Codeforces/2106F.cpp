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

class DSU{
public:
    vector<int>parent,size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int find_parent(int node){
        if(node==parent[node])return node;
        return parent[node]=find_parent(parent[node]);
    }
    void union_by_size(int u,int v){
        int pu = find_parent(u);
        int pv = find_parent(v);
        if(pu==pv)return;
        if(size[pu]>=size[pv]){
            size[pu]+=size[pv];
            parent[pv]=pu;
        }else{
            size[pv]+=size[pu];
            parent[pu]=pv;
        }
    }
};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        DSU ds(3*n);
        for(int i=1;i<=n;i++){
            int k = (i-1)*3;
            if(s[i-1]=='0'){
                ds.size[k]=i-1;
                ds.size[k+1]=0;
                ds.size[k+2]=n-i;
            }else{
                ds.size[k]=0;
                ds.size[k+1]=1;
                ds.size[k+2]=0;
            }
        }
        // for(int i=1;i<n;i++){
        //     int cur = i*3,prev = (i-1)*3;
        //     if(s[i]=='0' && s[i-1]=='0'){
        //         ds.union_by_size(cur,prev);
        //         ds.union_by_size(cur+2,prev+2);
        //     }
        //     else if(s[i]=='0' && s[i-1]=='1'){
        //         ds.union_by_size(prev+2,cur);
        //     }
        //     else if(s[i]=='1' && s[i-1]=='0'){
        //         ds.union_by_size(prev+1,cur);
        //     }
        // }
        for(int i=2;i<=n;i++){
            char cur = s[i-1], prev = s[i-2];
            int t = (i-1)*3, tp = (i-2)*3;
            if(cur=='0' && prev=='0'){
                ds.union_by_size(t,tp);
                ds.union_by_size(t+2,tp+2);
            }
            else if(cur=='0' && prev=='1'){
                ds.union_by_size(t,tp+1);
            }
            else if(cur=='1' && prev=='0'){
                ds.union_by_size(t+1,tp+2);
            }
        }
        int ans = 0;
        for(int i=0;i<(3*n);i++){
            if(ds.find_parent(i)==i){
                ans = max(ans,ds.size[i]);
            }
        }
        cout<<ans<<endl;
    }
}
