#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n,k;
        cin>>n>>k;
        vector<long long int>v(k+1,0);
        long long int b,c;
        for(int i=0;i<k;i++){
            cin>>b>>c;
            v[b]+=c;
        }
        sort(v.begin(),v.end(),greater<long long int>());
        int ans=0;
        for(int i=0;i<min(n,k);i++){
            ans+=v[i];
        }  
        cout<<ans<<endl; 
    }
}