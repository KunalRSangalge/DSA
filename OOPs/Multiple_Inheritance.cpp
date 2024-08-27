#include<bits/stdc++.h>
using namespace std;
class animal{
    public:
    int a;
    string name;
};
class human{
    public:
    int b;
    string n;
};
class hybrid: public animal,public human{
    public:
    int c;
};
int main(){
    hybrid x;
    cout<<x.a<<x.b<<x.c<<x.n<<x.name;
}