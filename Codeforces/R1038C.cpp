#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    ll base = 0;
    ll A = 0, B = 0;
    vector<ll> diff;
    for (int i = 0; i < n; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a > c) {
            base += a - c;
            A += a - c;
            a = c;
        }
        if (b > d) {
            base += b - d;
            B += b - d;
            b = d;
        }

        ll canGive = min(a, b);
        ll need = min(c - a, d - b);
        base += need;
        diff.push_back(min(canGive, need));
    }
    base += abs(A - B);
    sort(diff.rbegin(), diff.rend());
    ll save = 0;
    for (int i = 0; i < diff.size(); i++) {
        if (i < max(A, B)) {
            save += diff[i];
        } else {
            break;
        }
    }
    cout << base - save << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}