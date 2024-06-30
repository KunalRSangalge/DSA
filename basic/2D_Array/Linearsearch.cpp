#include<iostream>
using namespace std;

int main()
{
    int a[3][4];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        cin>>a[i][j];
    }
    cout<<"enter target"<<endl;
    int target;
    cin>>target;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        cout<<a[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(a[i][j]==target)
            {cout<<"yes,index is: "<<i<<j<<endl; break;}
        }
    }

}