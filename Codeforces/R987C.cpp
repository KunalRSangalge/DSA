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
        if(n%2==0){
            ll i=0,cnt=1;
            vector<ll>v(n,0);
            while(i<n){
                v[i]=cnt;
                v[i+1]=cnt;
                cnt++;
                i+=2;
            }
            for(auto x : v){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        else{
            if(n>=27){
                vector<ll>v(n+1,0);
                v[1]=1;
                v[10]=1;
                v[26]=1;
                v[23]=2;
                v[27]=2;
                ll cnt=3;
                for(ll i=2;i<10;i+=2){
                    v[i]=cnt;
                    v[i+1]=cnt;
                    cnt++;
                }
                for(ll i=11;i<23;i+=2){
                    v[i]=cnt;
                    v[i+1]=cnt;
                    cnt++;
                }
                v[24]=cnt;
                v[25]=cnt;
                cnt++;
                for(ll i=28;i<n;i+=2){
                    v[i]=cnt;
                    v[i+1]=cnt;
                    cnt++;
                }
                for(ll i=1;i<=n;i++){
                    cout<<v[i]<<" ";
                }
                cout<<endl;
            }
            else cout<<-1<<endl;
        }
    }
}