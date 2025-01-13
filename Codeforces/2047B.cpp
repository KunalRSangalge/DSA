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
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        map<char,int>mpp;
        for(ll i=0;i<n;i++){
            mpp[s[i]]++;
        }
        int cnt=0,maxi=0;
        char ch;
        for(auto x : mpp){
            if(x.second>maxi){
                maxi=x.second;
                ch=x.first;
            }
            cnt++;
        }
        if(cnt==1){
            cout<<s<<endl;
        }
        else{
            char minch;
            int mini=INT_MAX;
            for(auto x : mpp){
                if(x.first!=ch){
                    if(x.second<mini){
                        mini=x.second;
                        minch=x.first;
                    }
                }
            }
            for(int i=0;i<n;i++){
                if(s[i]!=ch){
                    if(s[i]==minch){
                        s[i]=ch;
                        break;
                    }
                }
            }
            cout<<s<<endl;
        }
}
}