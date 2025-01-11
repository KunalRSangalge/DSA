#include<bits/stdc++.h>
#define ll long long int
#define N 1e9
using namespace std;
vector<bool>prime(N+1,true);
// O(NloglogN) sieve of erastosthanes
void p(){
    prime[0]=false;
    prime[1]=false;
    for(ll i=0;i<N;i++){
        if(prime[i]){
            for(ll j=2*i;j<N;j+=i){
                prime[j]=false;
            }
        }
    }
}
vector<ll> div(ll n){
    vector<ll>div;
    for(ll i=1;i<=sqrt(n);i++){
        if(n%i==0){
            div.push_back(i);
            div.push_back(n/i);
        }
    }
    return div;
}
void yes(){
    cout<<"YES"<<endl;
}
void no(){
    cout<<"NO"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<pair<ll,ll>>a;
        vector<pair<ll,ll>>b;
        vector<pair<ll,ll>>c;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            a.push_back({x,i});
        }
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            b.push_back({x,i});
        }
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            c.push_back({x,i});
        }
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        sort(c.rbegin(),c.rend());
        // for(auto x : a){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        // for(auto x : b){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        // for(auto x : c){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        set<pair<ll,ll>>st;
        for(int i=0;i<3;i++){
            st.insert({a[i].first,a[i].second});
            st.insert({b[i].first,b[i].second});
            st.insert({c[i].first,c[i].second});
        }
        for(auto x : st){
            cout<<x.first<<" "<<x.second<<endl;
        }
        ll p = st.size()-1;
        ll i = 0;
        ll ans = 0;
        for(auto x : st){
            if(p<3){
                ans+=x.first;
            }
            p--;
        }
        cout<<ans<<endl;
    }
}