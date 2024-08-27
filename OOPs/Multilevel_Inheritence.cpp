#include<bits/stdc++.h>
using namespace std;
class animal{
    public:
    int age;
    string name;

};
class dog : public animal{
    public:
    string type;
};
class GP:public dog{
    public:
    string name;
};
int main(){
    GP p;
    p.age=10;
    p.name="fluffy";
    p.type="A";
    cout<<p.age<<p.name<<p.type;
    

}