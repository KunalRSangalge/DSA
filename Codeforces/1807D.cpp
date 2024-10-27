//brute force

#include<bits/stdc++.h>
using namespace std;
int change(int a[], int l, int r, int k,int n){
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        int a[n],psum[n];
        int sum=0;
        psum[0]=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            psum[i+1]=sum;
        }
        while(q--){
            int l,r,k;
            cin>>l>>r>>k;
            
            int ans = psum[n] - psum[r] + psum[l-1] + (r-l+1)*k;
            if(ans%2==0){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }

    }
}