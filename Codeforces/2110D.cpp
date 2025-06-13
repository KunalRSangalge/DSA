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

bool check2(ll k,ll n,vector<vector<pair<ll,ll>>>adj,vector<ll>b){
    set<pair<ll,ll>>st;
    vector<ll>max_battery(n+1,0);
    st.insert({min(k,b[1]),1});
    max_battery[1]=min(k,b[1]);
    while(!st.empty()){
        auto it = *(st.begin());
        ll cur_batteries = it.first;
        ll node = it.second;
        st.erase(it);
        for(auto iter : adj[node]){
            ll adjNode = iter.first;
            ll edgeWt = iter.second;
            // if(bat >= edgeWt){    
            //     vis[adjNode]=1;
            //     st.insert({bat,adjNode});
            // }
            if(cur_batteries>=edgeWt){
                ll new_bat = min(cur_batteries+b[adjNode],k);
                if(new_bat>max_battery[adjNode]){
                    max_battery[adjNode]=new_bat;
                    st.insert({new_bat,adjNode});
                }
            }

        }
    }
    if(max_battery[n]>0)return true;  
    return false;
}
bool check(ll k, ll n, vector<vector<pair<ll,ll>>>& adj, vector<ll>& b) {
    priority_queue<pair<ll,ll>> pq;
    vector<ll> max_battery(n+1, 0);
    pq.push({min(k, b[1]), 1});
    max_battery[1] = min(k, b[1]);

    while(!pq.empty()) {
        auto [cur_battery, node] = pq.top();
        pq.pop();
        if (cur_battery < max_battery[node]) continue;

        for(auto [adjNode, edgeWt] : adj[node]) {
            if(cur_battery >= edgeWt) {
                ll new_bat = min(cur_battery+ b[adjNode], k);
                if(new_bat > max_battery[adjNode]) {
                    max_battery[adjNode] = new_bat;
                    pq.push({new_bat, adjNode});
                }
            }
        }
    }

    return max_battery[n] > 0;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll>b(n+1);
        for(int i=1;i<=n;i++)cin>>b[i];

        vector<vector<pair<ll,ll>>>adj(n+1);
        for(ll i=0;i<m;i++){
            ll x,y,z;
            cin>>x>>y>>z;
            adj[x].push_back({y,z});
        }
        ll low=0,high=1e6,ans=-1;
        while(low<=high){
            ll mid = (high+low)/2;
            if(check(mid,n,adj,b)){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        cout<<ans<<endl;
    }
}
