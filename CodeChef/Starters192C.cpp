#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

inline ll abs64(ll x){ return x<0 ? -x : x; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--){
        ll X, Y, Z, C;
        cin >> X >> Y >> Z >> C;
        if (X == Y){
            cout << 0 << "\n";
            continue;
        }

        ll best = INF;

        // 1) one-heavy-op possibilities (heavy cost = C + |Z - k|)
        //    type-1: k | X  and  Y | k
        if (X % Y == 0) {
            // enumerate divisors d of X
            for (ll d = 1; d * d <= X; ++d){
                if (X % d) continue;
                // d is a divisor
                if (d % Y == 0)
                    best = min(best, abs64(Z - d) + C);
                ll d2 = X / d;
                if (d2 != d && d2 % Y == 0)
                    best = min(best, abs64(Z - d2) + C);
            }
        }
        //    type-2: k | Y  and  X | k
        if (Y % X == 0) {
            for (ll d = 1; d * d <= Y; ++d){
                if (Y % d) continue;
                if (d % X == 0)
                    best = min(best, abs64(Z - d) + C);
                ll d2 = Y / d;
                if (d2 != d && d2 % X == 0)
                    best = min(best, abs64(Z - d2) + C);
            }
        }

        // 2) two-heavy-op possibility: always achievable at cost = 2*C
        //    (just perform two heavies at Z itself, no need to move Z)
        best = min(best, 2 * C);

        cout << best << "\n";
    }
    return 0;
}
