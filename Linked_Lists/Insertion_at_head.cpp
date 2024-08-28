#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;    
}
void inserathead(Node* &head,int d){
    //create new Node
    Node* node2 = new Node(d); //this node2 will be within funcn ie temp;
    node2->next=head;
    head=node2;
}
int main(){
    Node* node1 = new Node(1);
    print(node1);
    inserathead(node1,2);
    print(node1);
    inserathead(node1,3);
    print(node1);
}