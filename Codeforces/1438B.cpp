#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    ll n;
    cin>>n;
    ll b[n];
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    map<ll,ll>mpp;
    bool flag=false;
    for(int i=0;i<n;i++){
        mpp[b[i]]++;
        if(mpp[b[i]]>1){
            flag=true;
            break;
        }
    }
    if(flag)cout<<"yes"<<endl;
    else cout<<"no"<<endl;

}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}