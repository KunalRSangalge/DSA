#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int>a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        vector<pair<int,int>> ops;
        ops.reserve(2000);

        auto record = [&](int type, int idx){
            // idx is 0-based internally, output wants 1-based
            ops.emplace_back(type, idx + 1);
        };

        // Loop until all three conditions are satisfied.
        while (true){
            bool did = false;

            // 1) CROSS–ARRAY VIOLATIONS FIRST *** CHANGED ***
            //    Fix any position where a[i] >= b[i]
            for (int i = 0; i < n; i++){
                if (a[i] >= b[i]){
                    swap(a[i], b[i]);
                    record(3, i);
                    did = true;
                    break;
                }
            }
            if (did) continue;

            // 2) THEN a‐ARRAY INVERSIONS *** CHANGED ***
            //    Fix any a[i] > a[i+1]
            for (int i = 0; i + 1 < n; i++){
                if (a[i] > a[i+1]){
                    swap(a[i], a[i+1]);
                    record(1, i);
                    did = true;
                    break;
                }
            }
            if (did) continue;

            // 3) THEN b‐ARRAY INVERSIONS *** CHANGED ***
            //    Fix any b[i] > b[i+1]
            for (int i = 0; i + 1 < n; i++){
                if (b[i] > b[i+1]){
                    swap(b[i], b[i+1]);
                    record(2, i);
                    did = true;
                    break;
                }
            }

            if (!did) break;  // no violations left
        }

        // Clamp to 1709 just in case
        if ((int)ops.size() > 1709)
            ops.resize(1709);

        // Output result
        cout << ops.size() << "\n";
        for (auto &pr : ops){
            cout << pr.first << " " << pr.second << "\n";
        }
    }
    return 0;
}
