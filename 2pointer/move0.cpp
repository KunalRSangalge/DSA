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

     int x=0,y=0,i=0;
        while(i<=n-1)
        {
            if(a[i]!=0)
            {swap(a[x],a[y]);x++;y++;}
            else 
            y++;
            i++;
        }
        for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
}