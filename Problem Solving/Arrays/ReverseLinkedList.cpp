#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;

    Node(int val){
        value=val;
        next=NULL;
    }
};
class Linkedlist{
public:
    Node* head;
    Node* tail;
    Linkedlist(){
        head=NULL;
        tail=NULL;
    }
    void insertAthead(int val){
        Node* new_node= new Node(val);
        new_node->next=head;
        head=new_node;
    }

    void reversell(){
        
    }
    void show(){
        Node* temp=head;
        while(temp != NULL){
            cout<<temp->value<<"->";
            temp=temp->next;
        }
        cout<<" NULL"<<endl;
    }
};

int main(){
    Linkedlist* l1=new Linkedlist();
    for(int i=0;i<10;i++){
        l1->insertAthead(i);  
    }
    l1->show();
    return 0;
}