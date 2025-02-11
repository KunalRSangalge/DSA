#include<bits/stdc++.h>
using namespace std;
vector<int>prime(int n){
    vector<int>v;
    vector<bool>prime(n+1,true);
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            for(int j=i*i;j<=n;j+=i)prime[j]=false;
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i])v.push_back(i);
    }
    // cout<<"ok1";
    return v;
}
vector<int>semiprime(int n,vector<int>p){
    vector<int>sp;
    for(int i=0;i<p.size();i++){
        for(int j=i;j<p.size();j++){
            long long x = 1LL * p[i]*p[j];
            if(x<=1e5) sp.push_back((x));
        }
    }
    // cout<<"ok";
    return sp;
}
vector<int> div(int n){
    vector<int>div;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            div.push_back(i);
            if(n/i != i) div.push_back(n/i);
        }
    }
    return div;
}
int main(){
    vector<int>p1=prime(1e5+1);
    vector<int>sp1=semiprime(1e5+1,p1);
    map<int,int>p;
    map<int,int>sp;
    // cout<<p1.size()<<" "<<sp1.size();
    for(int i=0;i<p1.size();i++)p[p1[i]]++;
    for(int i=0;i<sp1.size();i++)sp[sp1[i]]++;
    int t=1;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a.begin(),a.end());
        map<int,int>mpp;
        long long pcount=0,ans=0;
        for(int i=0;i<n;i++){
            mpp[a[i]]++;
            if(p.find(a[i])!=p.end()){
                ans+=pcount;
                ans-=(mpp[a[i]]-1);
                pcount++;
            }
            else if(sp.find(a[i])!=sp.end()){
                vector<int>getdiv = div(a[i]);
                for(int j=0;j<getdiv.size();j++){
                    ans+=mpp[getdiv[j]];
                }
            }
            // cout<<ans<<" ";
        }
        cout<<ans<<endl;
    }
}