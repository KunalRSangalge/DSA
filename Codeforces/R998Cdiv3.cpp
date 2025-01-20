#include<bits/stdc++.h>
#define ll long long int
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
bool cmp(vector<ll>&a,vector<ll>&b){
    return a[0]<b[0];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>>v(n,vector<ll>(m));
        for(ll i=0;i<n;i++){
            for(int j=0;j<m;j++)cin>>v[i][j];
        }
        // for(auto it : v){
        //     sort(it.begin(),it.end());
        // }
        for (auto &i : v)
        sort(i.begin(), i.end());
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[v[i][0]]=i+1;
        }
        sort(v.begin(),v.end(),cmp);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++)cout<<v[i][j]<<" ";
        //     cout<<endl;
        // }
        bool flag=true;
        for(int j=0;j<m;j++){
            for(int i=0;i<n-1;i++){
                if(v[i][j]>v[i+1][j]){
                    flag=false;
                    break;
                }
            }
            if(!flag)break;
        }
        if(flag){
            for(int i=0;i<m-1;i++){
                if(v[n-1][i]>v[0][i+1]){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            for(auto x: mpp){
                cout<<x.second<<" ";
            }cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}