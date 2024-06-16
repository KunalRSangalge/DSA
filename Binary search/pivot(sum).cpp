#include<iostream>
using namespace std;

int main()
{
    int n,ls=0,rs,total=0;
    cout<<"enter size"<<endl;
    cin>>n;
    int a[n];

    cout<<"enter ele"<<endl;
    for(int i=0;i<n;i++)
    cin>>a[i];

    for(int i=0;i<n;i++)
    total+=a[i];

    rs=total-a[0];

    for(int j=0;j<n;j++)
    {
        if(j!=0)
        {
            ls+=a[j-1];
            rs=total-ls-a[j];
        }
        if(ls==rs)
        {cout<<j; break;}
    }
}
