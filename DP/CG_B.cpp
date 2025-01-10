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
set<string> solve(set<string>&ans,int idx,string s,int n,int k,vector<int>&dp,map<char,int>&mpp,string temp){
    if(idx==n-1){
        ans.insert(temp);
        return ans;
    }
    // if(dp[idx]!=-1) return dp[idx];
     
    if(mpp[s[idx]]){
        solve(ans,idx+1,s,n,k,dp,mpp,temp+s[idx]);
    }
    solve(ans,idx+1,s,n,k,dp,mpp,temp);

    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    map<char,int>mpp;
    for(int i=0;i<k;i++){
        char ch;
        cin>>ch;
        mpp[ch]++;
    }
    // for(auto x:mpp){
    //     cout<<x.first<<x.second<<endl;
    // }
    int j=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(mpp[s[i]]) j=i;
        while(i<n && mpp[s[i]]){
            i++;
        }
        int x = i-j;
        ans+=((x)*(x+1))/2;
    }
    cout<<ans;
}