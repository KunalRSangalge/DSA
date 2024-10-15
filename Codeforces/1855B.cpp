#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        long long int l=1,ans=0;
        while(n%l==0){
            ans++;
            l++;
        }
        cout<<ans<<endl;
    }
}