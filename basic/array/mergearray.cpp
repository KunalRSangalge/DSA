#include<iostream>
using namespace std;


int main()
{
    int a[3]={2,4,7};
    int b[4]={3,5,9,10};
    int c[6];

    int i=0,j=0,k=0;
    while(i<3 && j<4)
    {
        if(a[i]<b[j])
        {c[k]=a[i];k++;i++;}
        else
        {c[k]=b[j];k++;j++;}
    }
    while(i<3)
    {c[k]=a[i];k++;i++;}
    while(j<4)
    {c[k]=b[j];k++;j++;}

    for(int i=0;i<6;i++)
    cout<<c[i]<<' ';
    
}