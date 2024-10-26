#include<bits/stdc++.h>
using namespace std;
#define ll long long
set<ll> f(ll a){
    set<ll>st;
    for(int i=1;i*i<=a;i++){
        if(a%i==0){
            if(i%2==0) st.insert(i);
            if((a/i)%2==0) st.insert(a/i);
        }
        

    }
    set<ll>ans;
    for(auto x : st){
        ans.insert(1+x/2);
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
      ll n,x;
      cin>>n>>x;
      set<ll> st=f(n-x);
     for(auto y : f(n+x-2)){
        st.insert(y);
     }
     ll ans=0;
     for(auto i : st){
        if(i>=x) ans++;
     }
     cout<<ans<<endl;
           
    }
}