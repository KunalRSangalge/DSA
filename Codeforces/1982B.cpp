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
        ll x,y,k;
        cin>>x>>y>>k;
        while(k>0 && x!=1){
            ll temp = y-(x%y);
            if(temp==0) temp=1;
            else temp = min(temp,k);
            x+=temp;
            while(x%y==0){
                x/=y;
            }
            k-=temp;
        }
        cout<<x+k%(y-1)<<endl;
    }
}