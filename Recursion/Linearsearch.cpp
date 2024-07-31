#include<bits/stdc++.h>
using namespace std;

bool ls(int a[], int target , int n){
    if(n==0) return 0;
    if(a[n-1]==target) return 1;
    return ls(a,target,n-1);   
}
int main(){
    int a[5]={1,2,3,4,5};
    int n=5;
    cout<<ls(a,0,n);
}