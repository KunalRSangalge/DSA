#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int carry=1,sum;

    while(carry!=0)
    {
        carry=(a&b)<<1;
        sum=a^b;
        a=sum;
        b=carry;
    }
    cout<<"sum= "<<a;

}