#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {

public :
          int nodeVal;
            Node* next;

Node(int data){

nodeVal=data;
next=NULL;

}



};

void insertAtStart(Node* &head,int data){

Node* new_node=new Node(data);
new_node->next=head;
head=new_node;


}


void displayNodes(Node* &head){

Node* temp=head;

while(temp!=NULL){

cout<<"-->"<<temp->nodeVal;
temp=temp->next;

}

cout<<"-->NULL"<<endl;  

}


int main(){
     
Node* head=NULL;

insertAtStart(head,10);
insertAtStart(head,20);
insertAtStart(head,30);
insertAtStart(head,40);
insertAtStart(head,50);
insertAtStart(head,60);
insertAtStart(head,70);
insertAtStart(head,80);
insertAtStart(head,90);


displayNodes(head);

return 0;


};