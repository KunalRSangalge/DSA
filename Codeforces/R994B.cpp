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
bool check(int i, int j,int n){
    vector<int>v(n+1);
    int x=1;
    for(int k=j;k<=n;k++){
        v[k]=x;
        x++;
    }
    for(int k=1;k<j;k++){
        v[k]=x;
        x++;
    }
    map<int,int>mpp;
    for(int k=1;k<=i;k++){
        mpp[v[k]]++;
    }
    for(int k=1;k<=i;k++){
        if(mpp[k]==0) return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        map<char,int>mpp;
        char p = 'p';
        char sc = 's';
        char dot = '.';
        for(int i=0;i<n;i++)mpp[s[i]]++;
        // cout<<"ok";
        if(mpp[sc]==n || mpp[p]==n || mpp[dot]==n) yes();
        else{
            int i=0;
            while(i!=n && s[i]!='p')i++;
            int j=n-1;
            while(j!=-1 && s[j]!='s')j--;

            if(i==n || j==-1) yes();
            else if(i<j)no();
            else{
                if(check(i+1,j+1,n))yes();
                else no();
            }
        }
    }
}