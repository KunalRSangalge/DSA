#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        ll n,x,k;
        cin>>n>>k>>x;
        ll curr=0;
        //vector<bool>vis(n+1,false);
        for(int i=0;i<k;i++) {curr+=(n-i);}// vis[n-i]=1;
        int m=n-k+1;
        ll ex=curr-x;
       
        int j=n;
        int i=1;
        if(ex==0){cout<<"YES"<<endl;
        continue;}
        else if(ex<0){
            cout<<"NO"<<endl;
            continue;
        }
        while(i<m&&j>i){
            if(ex==0) break;
            if(j-i<=ex){
                ex-=(j-i);
                j--;i++;
            }
            else {
                j--;
                m++;
            }
        }
       
        if(ex==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        
        
    }
    
}