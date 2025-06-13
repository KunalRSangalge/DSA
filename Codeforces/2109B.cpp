#include <bits/stdc++.h>
using namespace std;

// Fast Input/Output
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define ll long long

ll ceilLog2(long long n) {
    if (n <= 1) return 0;
    
    ll log = 0;
    n--;
    while (n > 0) {
        log++;
        n >>= 1;  // Divide n by 2
    }
    return log;
}

int main() {
    FAST_IO;
    ll t;
    cin >> t;
    while (t--) {
        ll n,m,a,b;
        cin>>n>>m>>a>>b;
        cout<<min({ceilLog2(n)+ceilLog2(b),ceilLog2(a)+ceilLog2(m),ceilLog2(n)+ceilLog2(m-b+1),ceilLog2(n-a+1)+ceilLog2(m)})+1<<endl;
    }
}
