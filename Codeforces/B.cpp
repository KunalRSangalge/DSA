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
        ll k;
        cin>>k;
        ll a[k];
        for(ll i=0;i<k;i++){
            cin>>a[i];
        }
        set<int>st;
        for(int i=0;i<k;i++){
            st.insert(a[i]);
        }
        ll n=k-2;
        for(int i=0;i<k;i++){
            if(n%a[i]==0){
                ll m=n/a[i];
                if(st.count(a[i]) && st.count(m)){
                    cout<<a[i]<<" "<<m<<endl;
                    break;
                }
            }
        }
    }
}