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
        ll odds,evens;
        if(n<5){cout<<-1<<endl; continue;}

        if(n%2==0){
            odds=n/2;
            evens=n/2;
        }
        else{
            odds=n/2+1;
            evens=n/2;
        }
        ll odd[odds], even[evens];

        for(ll i=0;i<odds;i++){
            odd[i]=2*i+1;
        }
        for(ll i=0;i<evens;i++){
            even[i]=(i+1)*2;
        }
        bool flag=true;
        for(int i=0;i<odds;i++){
            if(odd[i]!=5) cout<<odd[i]<<" ";
            else{
                if(i==odds-1) cout<<5<<" ";
                else{
                    i++;
                    cout<<odd[i]<<" ";
                    flag=false;
                }
            }
        }
        if(!flag)cout<<5<<" ";
        cout<<4<<" ";
        for(int i=0;i<evens;i++){
            if(even[i]!=4) cout<<even[i]<<" ";
        }
    }
}