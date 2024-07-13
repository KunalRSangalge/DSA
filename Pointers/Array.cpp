#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[10]={2,4,5};
    cout<<"address: "<<arr<<endl;
    cout<<"address: "<<&arr[0]<<endl;
    cout<<"value 0th: "<<*arr<<endl;
    cout<<"increament of 0th: "<<++(*arr)<<endl;
    cout<<"value of 1st: "<<*(arr+1)<<endl;
    int i=1;
    cout<<"other way: "<<i[arr]<<endl;
    cout<<"same as: "<<*(i+arr);

}