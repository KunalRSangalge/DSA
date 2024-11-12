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
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll t=n;
        vector<ll>v={11,10,111,101,110,100,1111,1110,1101,1011,1100,1010,1001,1000,11111,11110,11101,11011,10111,11100,11010,11001,10011,10101,10011,10001,11000,10100,10010,10000};
        for(ll i=0;i<v.size();i++){
            if(t==v[i]){
                t=1;
                break;
            }
        }
        if(t==1) yes();
        else{
            for(ll i=0;i<v.size();i++){
                if(n%v[i]==0){
                    n/=v[i];
                    i=-1;
                    // cout<<n<<" ";
                    if(n==1) break;
                }
            }
            if(n==1)yes();
            else no();
        }
    }
}