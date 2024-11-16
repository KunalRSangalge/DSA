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
        ll ans=0;
        ll i=1,cnt=0;
        while(i<n){
            if(a[i]==a[i-1]) {
                cnt++;
            }
            else{
                ans=max(cnt,ans);
                cnt=0;
            }
            i++;
        }
        ans=max(ans,cnt);
        cout<<n-ans-1<<endl;
    }
}