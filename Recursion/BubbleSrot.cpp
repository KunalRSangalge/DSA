#include<bits/stdc++.h>
using namespace std;

void bubsor(int a[],int i,int n){
    if(n==0) return ;
    if(a[i]>a[i+1]) swap(a[i],a[i+1]);
    if(i==(n-1)) {return bubsor(a,0,n-1);}    
    return bubsor(a,i+1,n);
}
int main(){
    int a[]={3,5,89,1,0};
    bubsor(a,0,4);
    for(int j=0;j<5;j++)
    cout<<a[j]<<" ";
}