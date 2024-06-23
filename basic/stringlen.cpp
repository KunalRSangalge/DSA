#include<iostream>
using namespace std;

int main()
{
    char name[20];
    cout<<"enter name"<<endl;
    cin>>name;

    int ans=0,i=0;
    while(name[i]!='\0')
    {
        ans++;
        i++;
    }
    cout<<ans;
}