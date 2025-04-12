#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>    
#include<ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll int64_t

#define fo(i,n) for (int i = 0; i < n; i++)
#define si(x) cin>>x
#define pi(x) cout<<x<<endl
#define pb push_back
#define all(x) x.begin(), x.end()
const ll mod =  1e9+7;
const ll INF = 1e18;

ll power(ll x, ll y, ll M = mod) {
    if(x == 0 && y == 0) return 1;
    if(y == 0) return 1;
    ll p = power(x, y / 2, M) % M;
    p = (p * p) % M;
    return (y % 2 == 0) ? p : (x * p) % M;
}

ll inverse(ll A, ll M) {
    return power(A, M - 2, M);
}

ll mul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

ll divide(ll a, ll b) {
    return mul(a, inverse(b, mod));
}

bool check(ll k, vector<vector<ll>>& a) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    ll n = a.size(), m = a[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<ll,ll>> q;
    q.push({0, 0});
    vis[0][0] = true;

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            ll nx = x + dx[d];
            ll ny = y + dy[d];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]) {
                if (abs(a[nx][ny] - a[x][y]) <= k) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    return vis[0][0] && vis[0][m-1] && vis[n-1][0] && vis[n-1][m-1];
}

ll findk(vector<vector<ll>>& a) {
    ll low = 0, high = 1e9, ans = -1;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (check(mid, a)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> a(n, vector<ll>(m));
    fo(i, n) fo(j, m) cin >> a[i][j];

    ll q;
    cin >> q;
    vector<ll> v(q);
    fo(i, q) cin >> v[i];

    ll mink = findk(a);

    ll vi = 0, dh = 0;
    for (int i = 0; i < q; i++) {
        if (v[i] >= mink) {
            if (i % 2 == 0) vi++;
            else dh++;
        }
    }

    cout << vi << " " << dh << endl;
}
