#include<bits/stdc++.h>
#define ll long long int
#define N 1e9
using namespace std;
vector<bool>prime(N+1,true);
// O(NloglogN) sieve of erastosthanes
void p(){
    prime[0]=false;
    prime[1]=false;
    for(ll i=0;i<N;i++){
        if(prime[i]){
            for(ll j=2*i;j<N;j+=i){
                prime[j]=false;
            }
        }
    }
}
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
        ll n,k;
        cin>>n>>k;
        ll a[n],maxi=0;
        for(ll i=0;i<n;i++){
            a[i]=i+1;
            maxi+=abs(a[i]-(n-i));
        }
        
        if(k%2||k>maxi){
            no();
            continue;
        }
        ll curr=2*(n-1);
        ll idx=0;
        while(k>0){
            ll x=min(k/2,curr/2)+ idx;
            
                k-=curr;
                swap(a[idx],a[x]);
                curr-=4;
                
                idx++;
            }
            yes();
            for(int i=0;i<n;i++) cout<<a[i]<<" ";
            cout<<endl;  
    }
        // if(k/2 <= max1){
        //     ll m = k/2;
        //     swap(a[0],a[m]);
        //     yes();
        //     for(int i=0;i<n;i++){
        //         cout<<a[i]<<" ";
        //     }cout<<endl;
        // }
        // else{
        //     ll count=0;
        //     if(n%2)count=n/2;
        //     else count=(n-1)/2;

        //     ll i=0,j=n-1;
        //     while(count--){
        //         ll num = pow(2,count);
        //         if(k/2 >= num){
        //             swap(a[i],a[j]);
        //             k-=2*num;
        //         }
        //         i++;
        //         j--;
        //     }
        //     // k=k/2-max1;
        //     // swap(a[0],a[n-1]);
        //     // count--;
            
        //     yes();
        //     for(int i=0;i<n;i++){
        //         cout<<a[i]<<" ";
        //     }cout<<endl;
        // }
    }
