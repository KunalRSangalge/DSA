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
int setbit(int n){
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        bool flag=true;
        vector<vector<int>>idx(27),ele(27);
    
        for(int j=1;j<=n;j++){
            idx[setbit(j)].push_back(j);
        }
        for(int i=0;i<n;i++){
            ele[setbit(a[i])].push_back(a[i]);
        }
        for(int i=1;i<=26;i++){
            sort(idx[i].begin(),idx[i].end());
            sort(ele[i].begin(),ele[i].end());
        }
        for(int i=1;i<=26;i++){
            if(idx[i].size()!=ele[i].size()){
                flag=false;
                break;
            }
            else{
                for(int j=0;j<idx[i].size();j++){
                    if(idx[i][j]!=ele[i][j]){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag==false)break;
        }
        
        if(flag)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}
