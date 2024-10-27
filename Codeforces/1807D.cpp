//brute force

#include<bits/stdc++.h>
using namespace std;
int change(int a[], int l, int r, int k,int n){
    int suml = 0, sumr=0;
    int idxl=0, idxr=n-1;
    l-=1;
    r-=1;
    int t=l,y=r,x=n-r-1;
    int ans =0;
    if(l>=0 && r>=0){
         while(l--){
            suml+=a[idxl++];
        }   
        while(x--){
            sumr+=a[idxr--];
        }
        ans = suml + sumr + (y-t+1)*k;
    }
    else{
        ans=-1;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        while(q--){
            int l,r,k;
            cin>>l>>r>>k;
            int ans = change(a,l,r,k,n);
            if(ans%2==0){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }

    }
}