#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t; cin >> t;
    while(t--) {
        ll n,enem=0;
        cin>>n;
        vector<ll> h(n);
        vector<ll> ind(n);
        for(ll i=0;i<n;i++) cin>>h[i];

        for(ll i=1;i<n-1;i++) {
            if(h[i-1]>h[i]&&h[i+1]>h[i] || h[i-1]<h[i]&&h[i+1]<h[i]) ind.push_back(i);
        }

        for(ll i=0;i<ind.size()-2;i++) {
          enem+=  (ind[i+1]-ind[i])*(n-1-ind[i+2]);
        }

        cout<<n*(n-1)/2-enem<<endl; 
    }
    return 0;
}