#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> parent(n + 1, 0);
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        parent[1] = 0;
        vector<int> bfs_order = {1};
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!visited[v] && v != parent[u]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                    bfs_order.push_back(v);
                }
            }
        }
        vector<ll> max_odd(n + 1, 0), max_even(n + 1, 0);
        vector<ll> threat(n + 1, 0);
        max_odd[1] = a[0];
        max_even[1] = -INF;
        threat[1] = max_odd[1];
        for (size_t i = 1; i < bfs_order.size(); ++i) {
            int v = bfs_order[i];
            int u = parent[v];
            if (u == 1) {
                max_even[v] = a[v - 1] - a[0];
                max_odd[v] = a[v - 1];
            } else {
                max_even[v] = a[v - 1] - max_odd[u];
                ll option = a[v - 1] - max_even[u];
                max_odd[v] = max(a[v - 1], option);
            }
            threat[v] = max(max_odd[v], max_even[v]);
        }
        for (int i = 1; i <= n; ++i) {
            cout << threat[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}