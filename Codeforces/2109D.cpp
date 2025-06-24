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


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        ll n,m,l;
        cin>>n>>m>>l;
        int sum=0,min_odd=INT_MAX;
        for(int i=0;i<l;i++){
            int x ; cin>>x;
            sum+=x;
            if(x%2) min_odd=min(min_odd,x);
        }
        vector<vector<int>>adj(n);
        for(int i=0;i<m;i++){
            ll u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //calculate the possiblility for walking upto the node
        int max_even=0,max_odd=0;
        if(sum%2){
            max_odd=sum;
            if(min_odd!=INT_MAX) max_even=sum-min_odd;
            else max_even=0;
        }
        else{
            max_even=sum;
            if(min_odd!=INT_MAX) max_odd =sum-min_odd;
            else max_odd=0;
        }
        // cout<<endl; cout<<min_odd<<" "<<max_even<<" "<<max_odd<<endl;
        //do dijkstra for min odd & even ditance from 1 to all node
        vector<vector<ll>>dist(n,vector<ll>(2,INT_MAX)); //dist[i][0]->min even path, dist[i][1]->min odd path
        queue<pair<ll,ll>>q;
        q.push({0,0});
        dist[0][0]=0; 
        while(!q.empty()){
            ll node = q.front().second;
            ll cur_dis = q.front().first;
            // cout<<cur_dis<<" ";
            
            q.pop();
            for(auto it : adj[node]){
                ll adjNode = it;
                if((cur_dis+1)%2==0 && (cur_dis+1) < dist[adjNode][0]){
                    dist[adjNode][0]=cur_dis+1;
                    q.push({dist[adjNode][0],adjNode});
                } 
                else if((cur_dis+1)%2!=0 && (cur_dis+1) < dist[adjNode][1]){
                    dist[adjNode][1] = cur_dis+1;
                    q.push({dist[adjNode][1],adjNode});
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<dist[i][0]<<" "<<dist[i][1]<<endl;
        // }
        string ans="";
        for(int i=0;i<n;i++){
            if(dist[i][0]<=max_even || dist[i][1]<=max_odd)ans+='1';
            else ans+='0';
        }
        cout<<ans<<endl;
    }
}
