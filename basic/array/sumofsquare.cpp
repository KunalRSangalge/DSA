#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter number "<<endl;
    cin>>n;

    for(int i=1;i<=sqrt(n);i++)
    {
        for(int j=1;j<=sqrt(n);j++)
        {
            if((i*i+j*j)==n)
            {cout<<i<<' '<<j<<endl;}
        }
    }
}