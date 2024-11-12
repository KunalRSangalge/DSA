#include<bits/stdc++.h>
#define ll long long
using namespace std;
void getpf(ll n){
    while(n%2==0){
        cout<<2<<" ";
        n/=2;
    }
    for(ll i=3;i<sqrt(n);i+=2){
        if(n%i==0){
            while(n%i==0){
                cout<<i<<" ";
                n/=i;
            }
        }
    }
    if(n>2) cout<<n<<" ";
}
int main(){
    ll n;
    cin>>n;
    getpf(n);
}