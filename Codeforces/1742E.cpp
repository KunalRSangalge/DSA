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
        ll n,q;
        cin>>n>>q;
        ll a[n],k[q];
        input(a,n);
        input(k,q);
        ll i=0,j=0,curr=0;
        ll step=0;
        vector<pair<ll,ll>>v;
        while(i<n){
            int temp=a[i];
            curr=a[i];
            while(i<n && temp>=curr){
                step+=a[i];
                i++;
                if(i<n)curr=a[i];
            }
            v.push_back(make_pair(temp,step));
        }
        vector<pair<ll,ll>>kk;
        for(int i=0;i<q;i++){
            kk.push_back(make_pair(k[i],i));
        }
        sort(kk.begin(),kk.end());
        i=0,j=0;
        int s = v.size();
        //check
        // for(int i=0;i<s;i++)cout<<v[i].first<<v[i].second<<endl;
        // for(int i=0;i<q;i++)cout<<kk[i].first<<kk[i].second<<endl;

        ll ans[q];
        while(j<q){
            while(i<s-1 && kk[j].first>v[i].first)i++;
            if(i>0 && kk[j].first<v[i].first)i--;
            if(i==0 && kk[j].first<v[i].first){ans[kk[j].second]=0;j++;continue;}
            ll x = kk[j].second;
            ans[x]=v[i].second;
            j++;
        }
        for(int i=0;i<q;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
}
