//memory limit exceeded but correct approach

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
void solve(set<string>&ans, string op,int n,int idx){
    if(ans.count(op))return;
    ans.insert(op);
    if(idx>=n) return;

    //remove 1st letter
    solve(ans,op.substr(1,n-idx),n,idx+1);
    
    //remove 2nd letter
    char ch=op[1];
    string temp = op.substr(1,n-idx);
    if(idx<n)solve(ans,op.erase(1,1),n,idx+1);
    op[1]=ch;
    if(op.size()>1){op.erase(2,op.size()-2);
    op+=temp;    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        set<string>ans;
        string op=s;
        solve(ans,op,s.size()-1,0);
        cout<<ans.size()<<endl;
    }
}