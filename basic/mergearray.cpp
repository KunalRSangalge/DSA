#include<iostream>
using namespace std;

void push(int a[],int x,int n)
{
    for(int i=n;i>x;i--)
    a[i]=a[i-1];
}
int main()
{
    int a[1]={0};
    int b[1]={1},k=1;

    for(int i=0;i<3;i++)
    {
        for(int j=k-1;j>=0;j--)
        {
            if(a[j]<=b[i])
            {
                push(a,j,k);
                k++;
                a[j+1]=b[i];
                break;
            }
        }
    }
    
    for(int i=0;i<6;i++)
    cout<<a[i]<<' ';
    //can just add then sort
}