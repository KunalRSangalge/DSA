#include<bits/stdc++.h>
using namespace std;

int main(){
    int num =5;
    int *ptr = &num;
    cout<<"address: "<<ptr<<endl;
    cout<<"value: "<<*ptr<<endl;

    double a = 4.5;
    double *p2 = 0;
    p2 = &a; //another way of initialisation
    cout<<"address: "<<p2<<endl;
    cout<<"value: "<<*p2<<endl;

    cout<<"size of num: "<<sizeof(num)<<endl;
    cout<<"size of ptr"<<sizeof(ptr)<<endl;
    cout<<"size of a: "<<sizeof(a)<<endl;
    cout<<"size of p2: "<<sizeof(p2)<<endl;

    cout<<"before inc: "<<num<<endl;
    (*ptr)++;
    cout<<"after inc: "<<num<<endl;

    //copying a pointer
    int *q = ptr;
    cout<<ptr<<"--"<<q<<endl;
    cout<<*ptr<<"--"<<*q<<endl;

    //doing ptr++
    cout<<ptr<<endl;
    ptr++;
    cout<<ptr<<endl;

}