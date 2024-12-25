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
        int x=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                x=i; break;
            }
        }
        if(x==-1){
            cout<<1<<" "<<s.size()<<" "<<1<<" "<<1<<endl;
            continue;
        }
        int l1=1,r1=s.size();
        // int l2=1;
        // if(x==s.size())l2=1;
        // else{
        //     if(s[x]=='1') l2=x-1;
        //     else l2=1;
        // }
        // int r2 = l2+(s.size()-x);
        int l2=-1,r2=-1;
        int sz=s.size()-x;
        int n = s.size();
        string ans="";
        for(int i=0;i<sz;i++)ans+='0';

        for(int i=0;i<=x;i++){
            string temp = "";
            for(int j=i;j<i+sz;j++){
                if((s[j]=='1' && s[x+j-i]=='0')||(s[j]=='0' && s[x+j-i]=='1')) temp+='1';
                else temp+='0';
            }
            if(temp>ans){
                ans=temp;
                l2=i;
                r2=i+sz-1;
            }
        }

        cout<<l1<<" "<<r1<<" "<<l2+1<<" "<<r2+1<<endl;
    }
}