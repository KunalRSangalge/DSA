#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        long long int w[n],h[n];
        for(int i=0;i<n;i++){
            cin>>w[i]>>h[i];
        }
        long long int peri=0;
        long long int maxh=INT_MIN,maxw=INT_MIN;
        for(int i=0;i<n;i++){
            int x=i-1;
            maxh=max(maxh,h[i]);
            maxw=max(maxw,w[i]);              
            
        }
        peri=2*(maxw+maxh);
        cout<<peri<<endl;
    }
}