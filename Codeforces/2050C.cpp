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
        string s;
        cin>>s;
        vector<int>f(2,0);
        ll n = s.size(),sum=0;
        while(n--){
            if(s[n]=='2')f[0]++;
            if(s[n]=='3')f[1]++;
            sum+=s[n]-'0';
        }
        if(sum%9==0){
            yes();continue;
        }
        // ll rem = (sum/9 + 1)*9 - sum;
        // cout<<rem<<endl;
        bool flag=false;
        for(int i=0;i<=min(10,f[0]);i++){
            for(int j=0;j<=min(10,f[1]);j++){
                if((sum+2*i+6*j)%9==0){
                    flag=true;
                    break;
                }
            }
            if(flag)break;
        }
        if(flag)yes();
        else no();
    }
}