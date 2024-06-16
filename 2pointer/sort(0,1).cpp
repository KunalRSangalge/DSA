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
    int i=0,j=n-1;
    while(i<j)
    {
        if(a[i]==0)
        i++;
        if(a[j]==1)
        j--;
        if(a[i]==1&&a[j]==0)
        swap(a[i],a[j]);
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<' ';
}