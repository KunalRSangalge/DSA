#include<bits/stdc++.h>
using namespace std;

int ways(int n){
    if(n==0 || n==1) return 1;
    return ways(n-1)+ways(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<"number of ways: "<<ways(n);
}