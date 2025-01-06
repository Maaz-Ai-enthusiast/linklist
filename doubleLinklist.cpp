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
        next = prev = NULL;
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
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertAtPosition(int data, int pos) {
        if (pos <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(data);
        cout << "Creating new node with data: " << data << endl;

        if (pos == 1) {
            cout << "Inserting at the beginning of the list." << endl;
            newNode->next = head;
            if (head != NULL) {
                head->prev = newNode;
                cout << "Updating previous head's previous pointer to new node." << endl;
            }
            head = newNode;
            cout << "New node is now the head of the list." << endl;
            return;
        }

        Node* temp = head;
        int count = 1;
        cout << "Traversing to position: " << pos << endl;
        while (temp != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
            cout << "Current node data: " << temp->val << ", position: " << count << endl;
        }

        if (temp == NULL) {
            cout << "Position out of bounds!" << endl;
            return;
        }

        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
            cout << "Updating next node's previous pointer to new node." << endl;
        }
        temp->next = newNode;
        newNode->prev = temp;
        cout << "Inserted new node with data: " << data << " at position: " << pos << endl;
    }


    void insertInSortedOrder(int data) {
        Node* newNode = new Node(data);

        // If the list is empty or the new node should be inserted at the beginning
        if (head == NULL || head->val >= data) {
            newNode->next = head;
            if (head != NULL) {
                head->prev = newNode;
            } else {
                tail = newNode; // If the list was empty, new node is also the tail
            }
            head = newNode;
            return;
        }

        Node* temp = head;
        // Traverse the list to find the correct position
        while (temp->next != NULL && temp->next->val < data) {
            temp = temp->next;
        }

        // Insert the new node
        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        } else {
            tail = newNode; // If the new node is inserted at the end, update the tail
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to clean up the memory
  ~doublyLinklist() {
    Node* temp;
    while (head != NULL) {
        temp = head;       // Get the current head node
        head = head->next; // Move head to the next node
        delete temp;       // Free memory for the current head node
    }
}

void delelteAtStart(){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}

void deleteAtEnd(){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
}

void deleteAtPosition(int pos){
    if(pos <= 0){
        cout<<"Invalid position"<<endl;
        return;
    }
    if(pos == 1){
        delelteAtStart();
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count < pos-1 && temp != NULL){
        temp = temp->next;
        count++;
    }
    if(temp == NULL || temp->next == NULL){
        cout<<"Position out of bounds"<<endl;
        return;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    free(toDelete);

}

 void updateAtPositon(int pos, int val){
    if(pos <= 0){
        cout<<"Invalid position"<<endl;
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count < pos && temp != NULL){
        temp = temp->next;
        count++;
    }
    if(temp == NULL){
        cout<<"Position out of bounds"<<endl;
        return;
    }
    temp->val = val;
 }

};

int main() {
    doublyLinklist dll;
    dll.insertAtStart(30);
    dll.insertAtStart(20);
    dll.insertAtStart(10);

    cout << "List after insertions: ";
    dll.printList();

    cout << "Inserting 40 at position 2." << endl;

    dll.insertAtPosition(40, 2);

    cout << "List after insertions: ";
    dll.printList();

    dll.delelteAtStart();

    cout << "List after deletion: ";

    dll.printList();
    // cout << "Head value: " << dll.head->val << endl;
    // cout << "Tail value: " << dll.tail->val << endl;

    return 0;
}
