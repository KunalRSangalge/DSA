#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
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
void deleting(Node* &head, int pos){
    Node* temp1 = head;
    Node* temp2 = head;
    if(pos==1){
        Node* temp = head;
        head=head->next;
        delete temp;
        return;
    }
    pos-=2;
    while(pos--){
        temp1=temp1->next;
        temp2=temp2->next;
    }

    temp2=temp2->next;
    temp1->next=temp2->next;  
    delete temp2;  
}
int main(){
    Node* node1= new Node(1);
    Node* tail= node1;
    Node* head= node1;
    print(head);
    insertattail(tail,2);
    print(head);
    insertattail(tail,3);
    print(head);
    deleting(head,3);
    print(head);
}