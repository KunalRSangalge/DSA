#include<bits/stdc++.h>
using namespace std;

bool srt(int a[],int n){
    
    if(n==0 || n==1) return 1;
    if(a[0]>a[1]) return 0;
    return srt(a+1,n-1);
}
int main(){
    cout<<"enter size";
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<srt(a,n);   
}