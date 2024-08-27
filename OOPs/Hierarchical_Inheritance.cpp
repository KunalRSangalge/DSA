#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    int a;
};
class B: public A{
    public:
    int b;
};
class C: public A{
    public:
    int c;
};
int main(){
    B obj1;
    cout<<obj1.b<<obj1.a;
}