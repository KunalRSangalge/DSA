#include<bits/stdc++.h>
using namespace std;
bool bs(int a[],int s, int e,int k){
    if(s>e) return 0;
    int mid=(s+e)/2;
    if(a[mid]==k) return 1;
    else if(a[mid]>k) bs(a,s,mid-1,k);
    else bs(a,mid+1,e,k);
}
int main(){
    int a[]={1,2,3,4,5};
    int n=5,k=0;
    cout<<bs(a,0,n,k);
}