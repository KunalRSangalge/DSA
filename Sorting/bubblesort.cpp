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

    bool flag=true;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {swap(a[j],a[j+1]); flag=false;}
        }
        if(flag==false)
        break; 
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<' ';
}