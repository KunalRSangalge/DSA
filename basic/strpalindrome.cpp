#include<iostream>
using namespace std;

int getlen(char ch[])
{
    int count=0;
    for(int i=0;ch[i]!='\0';i++)
    count++;

    return count;
}
int main()
{
    char ch[20];
    cin>>ch;

    int x=getlen(ch)-1,s=0,count=0;
    cout<<x<<endl;
    while(s<x)
    {
        if(ch[s]==ch[x])
        count++;

        s++;x--;
    }
    if(count==getlen(ch)/2)
    cout<<"palindrome";
    else
    cout<<"Not Palindrome";
  

}