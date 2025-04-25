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
    void insertAtarbitary(int val,int loc){
        Node* new_node = new Node(val);
        Node* temp=head;
        int cp=0;
        while(cp!=loc-1){
            temp=temp->next;
            cp++;
        } 
        new_node->next=temp->next;
        temp->next=new_node;
    }
    void insertAtend(int val){
        Node* New_node=new Node(val);
        Node* temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        New_node->next=NULL;
        temp->next=New_node;

    }
    Node* reverse() {
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* temp = curr->next;
            curr->next = prev;  // Update the next pointer to reverse the link
            prev = curr;
            curr = temp;
        }
        head = prev;  // Update the head to point to the new first node (prev)
        return head;  // Return the new head of the reversed list
    }

    void show(Node* &head){
        Node* temp=head;
        while(temp != NULL){
            cout<<temp->value<<"->";
            temp=temp->next;
        }
        cout<<" NULL"<<endl;
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
    Node* head=NULL;
    for(int i=0;i<10;i++){
        l1->insertAthead(i);  
    }
    l1->show();
    l1->insertAtarbitary(11,5);
    l1->show();
    l1->insertAtend(111);
    l1->show();
    Node* nh=l1->reverse();
    l1->show(nh);
    return 0;
}