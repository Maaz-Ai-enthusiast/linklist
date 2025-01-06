#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int data){
        val = data;
        next = NULL;
        prev = NULL;
    }
};  


class doublyLinklist{

public: 


Node* head;
Node* tail;
  
doublyLinklist(){

    head = NULL;
    tail = NULL;

}

void insertAtStart(int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;

};

int main(){
     
Node* newNode = new Node(10);
doublyLinklist dll;
dll.head = newNode;
dll.tail = newNode;

cout<<dll.head->val<<endl;
cout<<dll.tail->val<<endl;

return 0;

}
};