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

    int s=0,e=n-1,mid;
    while(s<e)
    {
        mid=(s+e)/2;

        if(a[mid]>a[e])
        s=mid+1;
        else
        e=mid;        
    }
    cout<<a[s];
}