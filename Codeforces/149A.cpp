#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,a[12],sum=0;
    cin>>k;
    for(int i=0;i<12;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+12);
    int m=0,n=11,count=0;
    while(m<k && n>=0){
        m+=a[n];
        n--;
        count++;
    }
    if(k>sum)cout<<"-1";
    else
    cout<<count;
}