#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        vector<int> x(n + 1), y(n + 1);
        for (int i = 1; i <= n; ++i) cin >> x[i];
        for (int i = 1; i <= n; ++i) cin >> y[i];

        vector<int> idx(n + 1);
        for (int i = 1; i <= n; ++i) idx[x[i]] = i;

        int cnt = 0, midIdx = -1;
        for (int i = 1; i <= n; ++i) {
            if (x[i] == y[i]) {
                cnt++;
                midIdx = i;
            }
        }

        if (n % 2 == 0) {
            if (cnt != 0) {
                cout << "-1\n";
                continue;
            }
        } else {
            if (cnt != 1) {
                cout << "-1\n";
                continue;
            }
        }

        vector<bool> vis(n + 1, false);
        vector<int> left, right;
        bool ok = true;

        for (int i = 1; i <= n; ++i) {
            if (x[i] == y[i] || vis[i]) continue;
            int j = idx[y[i]];
            if (j == i || y[j] != x[i]) {
                ok = false;
                break;
            }
            int a = i, b = j;
            if (a > b) swap(a, b);
            left.push_back(a);
            right.push_back(b);
            vis[i] = vis[j] = true;
        }

        int rem = n - (n % 2 == 1 ? 1 : 0);
        if ((int)left.size() * 2 != rem) {
            ok = false;
        }

        if (!ok) {
            cout << "-1\n";
            continue;
        }

        vector<int> ord(n + 1);
        int l = 1, r = n;
        for (size_t i = 0; i < left.size(); ++i) {
            ord[l++] = left[i];
            ord[r--] = right[i];
        }
        if (n % 2 == 1) {
            ord[(n + 1) / 2] = midIdx;
        }

        vector<int> cur(n + 1), pos(n + 1);
        for (int i = 1; i <= n; ++i) {
            cur[i] = i;
            pos[i] = i;
        }

        vector<int> resL, resR;
        for (int i = 1; i <= n; ++i) {
            if (cur[i] != ord[i]) {
                int j = pos[ord[i]];
                swap(cur[i], cur[j]);
                pos[cur[i]] = i;
                pos[cur[j]] = j;
                resL.push_back(i);
                resR.push_back(j);
            }
        }

        cout << resL.size() << "\n";
        for (size_t i = 0; i < resL.size(); ++i) {
            cout << resL[i] << " " << resR[i] << "\n";
        }
    }
    
    return 0;
}
