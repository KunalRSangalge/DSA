#include <bits/stdc++.h>
#define int long long
using namespace std;

int random(int a, int b) {
    return a + rand()%(b-a+1);
}

void solve() {
    int n = 100; // random(1, 100);
    int k = 1e18; // random(1, 1e18);
    cout << n << " " << k;
    cout << "\n";
    set<int>s;
    while(s.size()<n){
        s.insert(random(1,1e9));
    }    
    vector<int>a(s.begin(),s.end());
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout << "\n";
}



int32_t main() {
    srand(time(NULL));
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _TEST = 1000; // random(1, 1000);
    cout << _TEST << "\n";
    for(int _ = 1; _ <= _TEST; _++) {
        solve();
    }
    return 0;
        
}