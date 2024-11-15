#include<bits/stdc++.h>
#define ll long long int
using namespace std;
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
        ll n,m,k;
        cin>>n>>m>>k;
        ll ans=0;
        if(k==1) ans=1;
        else if(k==2 && m<=n) ans=m;
        else if(k==2 && m>n) ans = n+floor((m-n)/n);
        else if(k==3 && m<=n) ans=0;
        else if(k==3 && m>n) ans = m-n-floor((m-n)/n);
        else if(k>3) ans=0;
        cout<<ans<<endl;
    }
}