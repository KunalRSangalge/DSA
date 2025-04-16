#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool canAchieve(int x, int k, const unordered_map<int, int>& freq) {
    int count = 0;
    for (int i = 0; i < x; ++i) {
        if (freq.find(i) == freq.end()) return false;
        count += freq.at(i);
    }
    return count >= x * k;
}

int maxMEX(const vector<int>& a, int k) {
    unordered_map<int, int> freq;
    for (int num : a) {
        freq[num]++;
    }

    int low = 0, high = a.size() + 1, ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        bool ok = true;
        for (int i = 0; i < mid; ++i) {
            if (freq[i] < k) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        cout << maxMEX(a, k) << endl;
    }
    return 0;
}
