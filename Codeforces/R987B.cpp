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
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n-1;i++){
            if(a[i]!=i+1 && abs(a[i+1]-a[i])==1){
                swap(a[i],a[i+1]);
            }
        }
        ll b[n];
        for(ll i=1;i<=n;i++){
            b[i-1]=i;
        }
        bool flag=true;
        for(ll i=0;i<n;i++){
            if(b[i]!=a[i]){
                flag=false;
                break;
            }
        }
        if(flag) yes();
        else no();
    }
}