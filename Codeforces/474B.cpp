#include<bits/stdc++.h>
#define ll long long int
using namespace std;
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
        ll n,m;
        cin>>n;
        ll a[n],b[n];
        for(int i=0;i<n;i++) cin>>a[i];
        cin>>m;
        ll q[m];
        for(int i=0;i<m;i++) cin>>q[i];
        
        b[0]=a[0];
        for(int i=1;i<n;i++) b[i]=a[i]+b[i-1];

        for(int i=0;i<m;i++){
            ll low=0,high=n-1,mid;
            while(high>low){
                mid=(high+low)/2;

                if(q[i]<=b[mid]) high=mid;
                else low=mid+1; 
            }
            cout<<low+1<<endl;
        }
}