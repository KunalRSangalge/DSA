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
        ll a,b,l;
        cin>>a>>b>>l;
        vector<ll>ac;
        vector<ll>bc;
        vector<ll>divs = div(l);
        ll i=0;
        while(pow(a,i)<=1e6){
            ac.push_back(pow(a,i));
            i++;
        }
        i=0;
        while(pow(b,i)<=1e6){
            bc.push_back(pow(b,i));
            i++;
        }
        ll ans=0;
        for(ll i=0;i<divs.size();i++){
            ll k=divs[i];
            ll f=0;
            for(ll j=0;j<ac.size();j++){
                ll an=ac[j];
                for(ll x=0;x<bc.size();x++){
                    ll bn=bc[x];
                    if((k*an*bn)==l){
                        ans++;
                        f=1;
                        break;
                    }
                }
                if(f==1) break;
            }
        }
        cout<<ans<<endl;
    }
}