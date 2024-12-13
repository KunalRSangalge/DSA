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
        ll n,k;
        cin>>n>>k;
        if(n==1) cout<<1<<endl<<1<<endl;
        else if(k==1 || k==n) cout<<-1<<endl;
        else{
            int a = k-k%2;
            int b = k+1+k%2;
            cout<<3<<endl<<1<<" "<<a<<" "<<b<<endl;
        }
    }
}