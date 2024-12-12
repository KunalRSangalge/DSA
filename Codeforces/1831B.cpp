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
        ll a[n],b[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n;i++){
            cin>>b[i];
        }
        
        map<int,int>freq1;
        map<int,int>freq2;
        map<int,int>freq;
        for(int i=0;i<n;i++){
            int count=1;
            while(i!=n-1 && a[i]==a[i+1]) {
                count++;
                i++;
            }
            if(count>1){ freq1[a[i-1]]=max(count,freq1[a[i-1]]); } 
            else if(freq1[a[i]]==0) freq1[a[i]]++;   
        }
        for(int i=0;i<n;i++){
            int count=1;
            while(i!=n-1 && b[i]==b[i+1]) {
                count++;
                i++;
            }
            if(count>1) freq2[b[i-1]]=max(count,freq2[b[i-1]]); 
            else if(freq2[b[i]]==0) freq2[b[i]]++;       
        }
        int ans=0;
        for(auto x: freq1){
            freq[x.first]=x.second;
        }
        for(auto x: freq2){
            freq[x.first]+=x.second;
        }
        for(auto x: freq){
            ans=max(ans,x.second);
        }
        cout<<ans<<endl;
    }
}