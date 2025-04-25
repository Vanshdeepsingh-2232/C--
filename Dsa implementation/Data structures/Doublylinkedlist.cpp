#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* prev;
    Node* next;

    Node(int val){
        value=val;
        prev=NULL;
        next=NULL;
    }
};


class Doublylinkedlist{
    public:
    Node* head;
    Node* tail;

    Doublylinkedlist(){
        head=NULL;
        tail=NULL;
    }

    void insertatHead(int val){
        Node* new_node = new Node(val);
        if(head==NULL){
            tail=new_node;
            head=new_node;
        }
        else{
            new_node->next=head;
            head->prev=new_node;
            head=new_node;
        }
        
    }
    void insertatArbitrary(int val,int loc){
        Node* new_node = new Node(val);
        int cp=0;
        Node* temp = head;
        while(cp<(loc-1) && temp!=NULL)
        {
            temp=temp->next;
            cp++;
        }
        //next pointers
        new_node->next=temp->next;
        temp->next=new_node;
        //prev pointers 
        new_node->prev=temp;
        new_node->next->prev=new_node; 
    }
    /*
    void insertatEnd(int val){
        Node* new_node=new Node(val);
        

    }
    */

    void  showAddress(){
        Node* iter=head;
        while(iter!=NULL){
            cout<<"The real address = "<<&iter<<endl;
            cout<<"The value is = "<<iter->value<<endl;
            cout<<"The next address is = "<<iter->next<<endl;
            cout<<"The prev addres  is = "<<iter->prev<<endl;
            cout<<"-------------------------------------------------"<<endl;
            iter=iter->next;
        }
    }
    void show(){
        Node* iter=head;
        while(iter!=NULL){
            cout<<"The value is = "<<iter->value<<endl;
            iter=iter->next;
        }
    }

};

int main(){
    Doublylinkedlist d1;
    for(int i=0;i<10;i++){
        d1.insertatHead(i);
    }
    d1.showAddress();
  return 0;
}