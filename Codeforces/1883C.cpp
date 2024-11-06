#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll ans=INT16_MAX;
        if(k==2){
            
            for(ll i=0;i<n;i++){
                ll t = a[i]%2;
                ans=min(ans,t);
            }
        }
        if(k==3){
            
            for(ll i=0;i<n;i++){
                ll t = a[i]%3;
                if(t==0)ans=0;
                else ans=min(ans,k-t);           
            }
        }
        if(k==4){
            ll count=0,count4=0;
            for(ll i=0; i<n; i++){
                if(a[i]%4==0){count4++;}
                if(a[i]%2==0) count++;
            }
            if(count4>0)ans=0;
            else if(count>=2) ans=0; 
            else{
                ans = 2-count; 
                ll x=INT16_MAX;
                for(int i=0;i<n;i++){
                    ll t = a[i]%4;
                    x = min(x,4-t); 
                }
                ans = min(ans,x);
            }  
        }

        if(k==5){
            for(ll i=0;i<n;i++){
                ll t = a[i]%5;
                if(t==0) ans=0;
                else ans=min(ans,k-t);          
            }
        }
        cout<<ans<<endl;
    }
}