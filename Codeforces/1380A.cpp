#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool check(ll a[],int i){
    if(a[i+1]>a[i+2]) return true;
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        bool flag=false;
        for(ll i=0;i<n-1;i++){
            if(a[i]<a[i+1]){
                if(check(a,i)){
                    cout<<"YES"<<endl;
                    cout<<i+1<<" "<<i+2<<" "<<i+3<<endl;
                    flag=true;
                    break;
                }
            }
        }
        if(!flag)cout<<"NO"<<endl;
    }
}