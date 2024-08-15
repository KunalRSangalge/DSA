#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[m],maxi=0,mini=0,idx1=0,idx2=m-1;
    for(int i=0;i<m;i++)cin>>a[i];
    int b[m];
    for(int i=0;i<m;i++)b[i]=a[i];
    sort(a,a+m);
    int temp=n;
    //min
    while(temp){
        sort(a,a+m);
        if(a[idx1]!=0)
        {
            mini+=a[idx1];
            a[idx1]--;
            temp--;
        }
        else{
            idx1++;
        }
    }
    //max
    temp=n,idx1=0,idx2=m-1;
    while(temp){
        sort(b,b+m);
        if(b[idx2]!=0){
            maxi+=b[idx2];
            b[idx2]--;
            temp--;
        }
        else{
            idx2--;
        }
    }
    cout<<maxi<<" "<<mini;
}