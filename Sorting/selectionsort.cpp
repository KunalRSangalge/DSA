#include<iostream>
using namespace std;

int min(int a[],int x,int y)
{
    int m=INT16_MAX,n;
    for(int i=x;i<y;i++)
    {
        if(a[i]<m)
        {m=a[i];n=i;}
    }
    return n;
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

    for(int i=0;i<n;i++)
    {
        swap(a[i],a[min(a,i,n)]);
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<' ';
}