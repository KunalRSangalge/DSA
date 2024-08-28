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
void inserathead(Node* &head,int d){
    //create new Node
    Node* node2 = new Node(d); //this node2 will be within funcn ie temp;
    node2->next=head;
    head=node2;
}
void insertin(Node* &tail,Node* &head,int d,int pos){
    Node* temp = head;
    if(pos==1){
        inserathead(head,d);
        return;
    }

    //checking pos
    pos--;
    while(pos--){
        temp=temp->next;
    }

    //adding if pos == last
    if(temp->next == NULL){
        insertattail(tail,d);
        return;
    }

    //creating a LL
    Node* node = new Node(d);
    node->next=head->next;
    head->next = node;

}
int main(){
    Node* node1= new Node(1);
    Node* tail= node1;
    Node* head= node1;
    print(node1);
    insertattail(tail,2);
    print(node1);
    insertattail(tail,4);
    print(node1);
    insertattail(tail,5);
    print(node1);
    insertin(tail,head,0,1);
    print(head);
    insertin(tail,head,6,5);
    print(head);
    cout<<"head at ->"<<head->data<<endl;
    cout<<"tail at ->"<< tail->data<<endl;
}