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

    int li,ri;
    cout<<"enter left index"<<endl;
    cin>>li;
    cout<<"enter right index"<<endl;
    cin>>ri;

    while(li<=ri)
    {
        swap(a[li],a[ri]);
        li++;ri--;
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<' ';
}