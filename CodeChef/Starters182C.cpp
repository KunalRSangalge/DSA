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
        bool ispal(string s){
            int i=0,j=s.size()-1;
            while(i<j){
                if(s[i]!=s[j]) return false;
                i++;
                j--;
            }
            return true;
        }
        int f(int i,string s,string t,vector<int>&dp){
            if(i<0){
                if(ispal(t)) return t.size();
                else return INT_MIN;
            }
            
            t+=s[i];
            int pick = f(i-1,s,t,dp);
            t.pop_back();
    
            int notpick = f(i-1,s,t,dp);
    
            return  max(pick,notpick);
        }
        int longestCommonSubsequence(string text1, string text2) {
            int n = text1.size();
            int m = text2.size();
            vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    
            for(int i=0;i<=n;i++) dp[i][0]=0;
            for(int i=0;i<=m;i++) dp[0][i]=0;
    
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(text1[i-1] == text2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                    else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
            return dp[n][m];
        }
        int longestPalindromeSubseq(string s) {
            int n = s.size();
            string s2="";
            for(int i=n-1;i>=0;i--){
                s2+=s[i];
            }
            return longestCommonSubsequence(s,s2);
        }
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        ll x,y,z;
        cin>>x>>y>>z;
        vector<ll>v;
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);
        sort(v.begin(),v.end());
        ll a=v[0],b=v[1];
        ll ans=0;
        if(a%2==1 && b%2==1){
            ans = a+b-1;
        }
        else ans = a+b;
        cout<<ans<<endl;
    }
}
