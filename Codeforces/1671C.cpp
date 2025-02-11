#include <bits/stdc++.h>
 
using namespace std;

#define ll long long

int main()
{
  ll t;
  cin >> t;
  while(t--){
    ll n,x;
    cin >> n >> x;
    vector <ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    ll cnt = 0;
    ll k = 0;
    for(ll i = 0; i < n; i++){
        x -= v[i];
        cnt++;
        if(x >= 0) k += x/cnt+1;
    }
    cout << k << endl;
  }
  return 0;
} 
