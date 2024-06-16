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

    int i=0,j=0,k=n-1;
    while(j<=k)
    {
        if(a[j]==0)
        {swap(a[i],a[j]); i++;j++;}

        else if(a[j]==1)
        j++;

        else
        {swap(a[k],a[j]); k--;}
    }
    for(int i=0;i<n;i++)
    cout<<a[i];
}