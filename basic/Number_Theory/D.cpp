#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){   
    ll n;
    cin>>n;
    set<ll>v;
    for(ll i=1;i<=n;i++){
        ll sum=0;
        bool flag = false;
        for(ll j=0;j<=n;j++){
            int k = 1+j*i;
            if(j!=0 && k%n==1){flag = true; break;}
            if((k)%n == 0){
                sum+=n;
            }
            sum+=(k)%n;
        }
        if(flag) v.insert(sum);
    }
    for(auto x : v){
        cout<<x<<" ";
    }
    cout<<endl;
}
