//tle
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){   
    ll n;
    cin>>n;
    set<ll>st;
   for(int i=1;i<=sqrt(n);i++){
    if(n%i==0){
        ll k=n/i;
        ll a=(k*(2+(k-1)*i))/2;
        ll b=(i*(2+(i-1)*k))/2;
        st.insert(a);
        st.insert(b);
    }
   }
    for(auto x : st) cout<<x<<" ";
}
