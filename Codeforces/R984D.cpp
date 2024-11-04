#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<cstdio>
using namespace __gnu_pbds;
using namespace std;
#define ll int64_t
 
// Ordered Set Tree
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
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
 
 
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
 
int rng(int lim)
{
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}
int mpow(int base, int exp);
 
 
const ll mod =  1e9+7;
const ll N = 2e5+4,M=502;
 
const ll INF= 1LL*1001*1001*1001*1001*1001*1001 ;
//=======================
 
 
 
/*int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}*/
 
void myerase(ordered_set &t, int v){
    int rank = t.order_of_key(v);//Number of elements that are less than v in t
    ordered_set::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}
class segTree{
    private :
    vector<ll>tree;
    int n;
    void built(vi &a,int l,int r,int idx){
        if(l>r) return;
        if(l==r){tree[idx]=a[l];
        return;}
        int mid=(l+r)/2;
        built(a,l,mid,2*idx+1);
        built(a,mid+1,r,2*idx+2);
        tree[idx]=(tree[2*idx+1]+tree[2*idx+2]);
    }
    ll query(int x,int y,int l,int r,int idx){
        if(r<x||l>y) return 0LL;
        if(l>=x&&r<=y) return tree[idx];
        int m=(l+r)/2;
        return (query(x,y,l,m,2*idx+1) +query(x,y,m+1,r,2*idx+2));
    }
    void update(int node, int start, int end, int l, int r, int val)
{
   
    if (start > end or start > r or end < l)
        return;
 
   
    if (start == end)
    {
       
        tree[node] += val;
        return;
    }
 
   
    int mid = (start + end) / 2;
    update(node*2+1, start, mid, l, r, val);
    update(node*2 + 2, mid + 1, end, l, r, val);
 
   
    tree[node] = tree[node*2+1] + tree[node*2+2];
}
    public :
    void built(vi &a,int l,int r){
        built(a,l,r,0);
 
    }
    ll query(int x,int y){
        return query(x,y,0,n-1,0);
    }
    void update(int l,int r,int val){
        update(0,0,n-1,l,r,val);
            }
    segTree(int N){
        tree.resize(4*N,0LL);
      n=N;
    }
 
};
ll power(ll x, ll y, ll M)
{
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
        ll n,m;
        cin>>n>>m;
        vector<string>a(n);
        fo(i,n) cin>>a[i];
        vector<string>curr;
         int mincol=0;
        int minrow=0;
        int maxcol=m-1;
       int maxrow=n-1;
        
        while(maxcol>=mincol&&maxrow>=minrow){
            string v="";
            for(int i=mincol;i<=maxcol;i++){v.push_back(a[minrow][i]);}
            minrow++;
            for(int i=minrow;i<=maxrow;i++){v.push_back(a[i][maxcol]);}
            maxcol--;
            if(maxcol<mincol||maxrow<minrow){
                curr.pb(v);
                break;
            }
            for(int i=maxcol;i>=mincol;i--){v.push_back(a[maxrow][i]);}
            maxrow--;
            for(int i=maxrow;i>=minrow;i--){v.push_back(a[i][mincol]);}
            mincol++;
            curr.pb(v);
        }
        ll ans=0;
      
 
        for(int i=0;i<curr.size();i++){
        int idx=-1;
        string st="";
        for(int j=0;j<curr[i].size();j++){
            if(curr[i][j]=='1'&&idx==-1){
                idx=j;
                
            }
            if(idx!=-1){
                st.push_back(curr[i][j]);
            }
 
        }
        if(idx==-1) continue;
        for(int j=0;j<idx;j++) st.push_back(curr[i][j]);
       
        for(int i=0;i<st.size();i++){
            if(st.substr(i,4)=="1543") ans++;
        }
 
        }
        cout<<ans<<endl;
       
 
}}