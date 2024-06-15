#include<iostream>
using namespace std;

int main()
{
    int n,target;
    cout<<"enter size"<<endl;
    cin>>n;
    int a[n];
    cout<<"enter ele"<<endl;
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"enter target"<<endl;
    cin>>target;
    int start=0,end=n-1,mid;
        while(start<=end)
        {
            mid=(start+end)/2;
            if(a[mid]==target)
            cout<<mid;
            else if(target>a[mid])
            start=mid+1;
            else
            end=mid-1;
        }
        
}
