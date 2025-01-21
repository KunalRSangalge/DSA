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
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        // if(n==1){cout<<-1<<endl;continue;}
        char ch;
        bool flag=false;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                ch=s[i];
                flag=true;
                break;
            }
        }
        if(flag){
            string ans;
            ans+=ch;
            ans+=ch;
            cout<<ans<<endl;
        }
        else{
            if(n<3)cout<<-1<<endl;
            else
            {   bool flag1=false;
                for(int i=0;i<n-2;i++){
                    if(s[i]!=s[i+1] && s[i]!=s[i+2] && s[i+1]!=s[i+2]){
                        cout<<s[i]<<s[i+1]<<s[i+2]<<endl;
                        flag1=true;
                        break;
                    }
                }
                if(!flag1)cout<<-1<<endl;
            }
        }
        
    }
}