#include<bits/stdc++.h>
using namespace std;

int sum;
int digits(int a[],int n,int b[],int m)
{
    int num1=0,num2=0,t,digit=0;
    for(int i=n-1;i>=0;i--)
    num1+=a[i]*pow(10,n-i-1);

    for(int i=m-1;i>=0;i--)
    num2+=b[i]*pow(10,m-i-1);

    sum=num1+num2;
    t=sum;
    while(t!=0)
    {
        t/=10;
        digit++;
    }
    return digit;
}
int main()
{
    int n;
    cout<<"enter size"<<endl;
    cin>>n;
    int a[n];
    cout<<"enter ele"<<endl;
    for(int i=0;i<n;i++)
    cin>>a[i];

    int m;
    cout<<"enter size"<<endl;
    cin>>m;
    int b[m];
    cout<<"enter ele"<<endl;
    for(int i=0;i<m;i++)
    cin>>b[i];

    int x=digits(a,n,b,m);
    int c[x];
    cout<<x<<endl<<sum<<endl;
    
    for(int i=x-1;i>=0;i--)
    {
        c[i]=sum%10;
        sum/=10;
    }
    for(int i=0;i<x;i++)
    cout<<c[i]<<' ';

}