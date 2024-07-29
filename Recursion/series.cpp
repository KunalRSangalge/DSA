#include<bits/stdc++.h>
using namespace std;

int series(int n){
    if(n==0) return 1;
    series(n-1);
    cout<<n;
}
int main(){
    int n=7;
    series(n);
}