#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
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
    Node* temp = new Node(d);
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
}

void deleting(Node* &head, int pos){
    if(pos==1){
        head=head->next;
        head->prev=NULL;
        return;
    }
    Node* temp1 = head;
    Node* temp2 = head;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    temp2=temp1->next->next;
    temp1->next=temp2;
    temp2->prev=temp1;

}

int main(){
    Node* node1 = new Node(1);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    insertattail(tail,2);
    print(head);
    insertattail(tail,3);
    print(head);
    insertattail(tail,3);
    print(head);
    insertattail(tail,4);
    print(head);
    insertattail(tail,5);
    print(head);
    deleting(head,2);
    print(head);
    
}