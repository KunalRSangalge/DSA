#include<iostream>
using namespace std;

int main()
{
    cout<<"enter row and coloumn"<<endl;
    int n,m,sum=0,t,x;
    cin>>n>>m;
    int a[n][m];
    cout<<"enter ele"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>a[i][j];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cout<<a[i][j]<<' ';
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        t=sum;
        sum=0;
        for(int j=0;j<m;j++)
        {sum+=a[i][j];
         if(sum>t)
         {t=sum;x=i;}
        }
    }
    cout<<sum<<' '<<x;
}