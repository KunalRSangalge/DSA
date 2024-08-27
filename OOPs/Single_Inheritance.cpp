#include<bits/stdc++.h>
using namespace std;
class animal{
    public:
    int age;
};
class dog : public animal{
    public:
    int type;
};

int main(){
    dog fluffy;
    fluffy.age=10;
    fluffy.type=4;
    cout<<fluffy.age;
}