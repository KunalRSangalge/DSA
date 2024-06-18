#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter number "<<endl;
    cin>>n;

    int s=0,e=sqrt(n);
    while(s<e)
    {
        int sq=s*s+e*e;
        if(sq==n)
        {cout<<s<<' '<<e<<endl;break;}
        else if(sq<n)
        s++;
        else
        e--;   
        
    }
}