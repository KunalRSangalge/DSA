#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>   
#include <ext/pb_ds/tree_policy.hpp>  
#include<cstdio>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define N 1e9
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
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
        ll n,x,y;
        cin>>n>>x>>y;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll sum=0,ans=0;
        for(int i=0;i<n;i++) sum+=a[i];
        ordered_set s;
        for(int i=0;i<n;i++){
            // ll p = s.size()-s.order_of_key(x+a[i]);
            // ll q = s.size() - s.order_of_key(y+a[i]+1);
            ans += (s.order_of_key(y+a[i]+1)-s.order_of_key(x+a[i]));
            s.insert(sum-a[i]);
        }
        cout<<ans<<endl;
    }
}