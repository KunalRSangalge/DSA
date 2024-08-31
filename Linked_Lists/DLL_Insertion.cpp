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

void insertathead(Node*& head, int d){
    Node*temp = new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;    
}

void insertattail(Node* &tail,int d){
    Node* temp = new Node(d);
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
}
void inserting(Node* &head, int d, int pos){
    Node* before = head;
    if(pos==1){
        insertathead(head,d);
        return;
    }
    pos--;
    while(pos--){
        before=before->next;
    }

    if(before->next==NULL){
        insertattail(before,d);
        return;
    }
    
    Node* after = before->next;

    Node* temp = new Node(d);
    before->next=temp;
    before->prev=head;

    after->prev=temp;
    temp->next=after;


}   
int main(){
    Node* node1 = new Node(1);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    insertathead(head,2);
    print(head);
    insertathead(head,3);
    print(head);
    insertattail(tail,4);
    print(head);
    insertattail(tail,5);
    print(head);
    inserting(head,7,5);
    print(head);
}