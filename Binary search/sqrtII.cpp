//value of sqrt upto 4 decimal places
#include<bits/stdc++.h>
using namespace std;

double left(int n){
    double s=0,e=n,ans=0;
    long long int mid;

    while(s<=e){
        mid=(s+e)/2;
        if((mid*mid)==n) return mid;
        else if((mid*mid) > n) e=mid-1; 
        else {s=mid+1; ans=mid;}
    }
    return ans;
}
double sqrrt(int n){
    double ans;
    ans = left(n);
    double s,e,i=1,mid;
    s=ans,e=ans+0.9999;
    while(s<=e){
        mid=(s+e)/2;
        if((mid*mid) > n) e=mid-0.0001;
        else 
        {s=mid+0.0001; ans=mid;}
    }
    return ans;
}
int main(){
    cout<<"enter number: "<<endl;
    double n,k;
    cin>>n;
    cout<<left(n)<<endl<<sqrrt(n);
}

