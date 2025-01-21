#include<bits/stdc++.h>
#define ll int64_t
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
ll solve(vector<ll>&a,ll n,ll i,ll k){
    ll l = i, r = n-1;
    ll ans=-1;
    while(l<=r){
        ll m = l + (r - l) / 2;
        if(a[m]<k){
            ans=a[m];
            break;
        }
        else{
            r=m-1;
        }
    }
    return ans;
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
        sort(a,a+n);
        map<int,int>mpp;
        for(int i=0;i<n;i++)mpp[a[i]]++;
        bool flag=false,flag1=false;
        ll count=0,countsq=0;
        vector<ll>v;
        for(auto x : mpp){
            if(x.second>3){
                flag1=true;
                countsq=x.first;
            }
            if(x.second>1){
                v.push_back(x.first);
                count++;
                if(count==2){
                    flag=true;
                    break;
                }
            }
        }
        if(flag){
            cout<<v[0]<<" "<<v[0]<<" "<<v[1]<<" "<<v[1]<<endl;
        }
        else if(flag1){
            for(int i=0;i<4;i++)cout<<countsq<<" ";
            cout<<endl;
        }
        else{
            if(count==0){
                cout<<-1<<endl;
            }
            else if(count==1){
                bool flag2=true;
                
                vector<ll>b;
                ll cnt=0;
                for(int i=0;i<n;i++){
                    if(a[i]==v[0] && cnt<2)cnt++;
                    else b.push_back(a[i]);
                }
                // cout<<v[0]<<endl;
                // for(int i=0;i<b.size();i++)cout<<b[i]<<" ";cout<<endl;
                ll x = 2*v[0];
                for(int i=0;i<b.size();i++){
                    ll y = solve(b,b.size(),i+1,x+b[i]);
                    if(y!=-1){
                        cout<<v[0]<<" "<<v[0]<<" "<<b[i]<<" "<<y<<endl;
                        flag2=false;
                        break;
                    }
                }
                if(flag2)cout<<-1<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
    }
}