// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// class Node {
//     public:
//     int val;
//     Node* next;
//     Node(int data) {
//         val = data;
//         next = NULL;
//     }
// };




// int main() {
    
//     Node n(10); // Create a Node object on the stack

//     cout << n.val << "-----" << endl; // Access the member using the dot operator
//     cout<<n.next << "-----" << endl;
//      cout<<"address of the node n: "<<&n<<endl;
//     return 0;
// }











#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;// Pointer to the next Node objectexp
    Node(int data){
        this->val = data;
        // val = data;
        next = NULL; 
    }
};


// insert a node into start of linklist

void insertAtStart(Node* &head, int data){
    Node* n = new Node(data);
    n->next = head;
    head = n; 
  
}
int main(){
// here  n is a pointer to a Node object, not the object itself. 
// It points to the memory location where the Node object is stored
    Node* n1 = new Node(10);

    cout<<n1->val<<"-----"<<endl;
    cout<<n1->next<<"-----"<<endl;
    cout<<"address of the node n1: "<<n1<<endl;



return 0;
}