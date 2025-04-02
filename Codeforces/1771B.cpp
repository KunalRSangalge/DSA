#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        
        vector<int> bad(n + 2, n + 1); // bad[i] stores the min 'y' for x=i

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            bad[x] = min(bad[x], y);
        }

        // Propagate min bad value forward
        for (int i = n - 1; i >= 1; i--) {
            bad[i] = min(bad[i], bad[i + 1]);
        }

        ll ans = 0, j = 1;
        for (int i = 1; i <= n; i++) {
            while (j < bad[i]) j++; // Expand valid subarray
            ans += (j - i);
        }

        cout << ans << "\n";
    }

    return 0;
}
