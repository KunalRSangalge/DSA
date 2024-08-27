#include<bits/stdc++.h>
using namespace std;
class Hero{

    private:
    int value;

    public:
    int health;
    
    int getvalue(){
        return value;
    }
    void setvalue(int n){
        value=n;
    }
};
int main(){
    Hero h1;
    h1.health=10;
    cout<<h1.getvalue()<<endl;
    h1.setvalue(80);
    cout<<h1.getvalue();
}