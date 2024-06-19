#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter size"<<endl;
    cin>>n;
    char a[n];
    cout<<"enter ele"<<endl;
    for(int i=0;i<n;i++)
    cin>>a[i];

    char goal[]="cdeab";
    int count=0;

    for(int i=0;i<n;i++)
    {   
        char t=a[n-1];
        for(int j=n-1;j>0;j--)
        {
            a[j]=a[j-1];
        }
        a[0]=t;

        for(int k=0;k<n;k++)
        {
            if(a[k]==goal[k])
            count++;
        }
        if(count==n)
        cout<<"yes";
        else 
        count=0;
    }

}