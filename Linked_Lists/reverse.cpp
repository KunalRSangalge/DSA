#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};
void print(Node* tail){
    while(tail!=NULL){
        cout<<tail->data<<" ";
        tail=tail->next;
    }
    cout<<endl;
}
void insertattail(Node* &tail,int d){
    //creating a LL
    Node* node = new Node(d);

    //adding
    tail->next=node;
    tail=node;
}
void reverse(Node* curr){
    
    Node* prev=NULL;
    Node* forw=curr->next;

    while(curr!=NULL){
        forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
    }
    
}
int main(){
    Node* node1= new Node(1);
    Node* head=node1;
    Node* tail= node1;
    print(node1);
    insertattail(tail,2);
    print(node1);
    insertattail(tail,3);
    print(node1);
    insertattail(tail,4);
    print(node1);
    insertattail(tail,5);
    print(node1);
    reverse(head);  
    print(tail);
    
}