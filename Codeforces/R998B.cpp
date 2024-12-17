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
        int k;
        cin>>k;
        int a[k];
        for(int i=0;i<k;i++){
            cin>>a[i];
        }
        int n = k-2;
        map<int,int>mpp;
        for(int i=0;i<k;i++) mpp[a[i]]++;

        for(int i=0;i<k;i++){
            if(n%(a[i])==0){ 
                if((n/a[i]) == a[i]){
                    if(mpp[a[i]] > 1){
                        cout<<a[i]<<" "<<a[i]<<endl;
                        break;
                    }
                }
                else if(mpp.count(n/a[i])){
                    cout<<a[i]<<" "<<n/a[i]<<endl;
                    break;
                }
                
            }
        }
    }
}