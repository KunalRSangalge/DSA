#include<iostream>
using namespace std;

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
        int j,t=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>t)
            a[j+1]=a[j];

            else
            break;
        }
        a[j+1]=t;
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<' ';
}