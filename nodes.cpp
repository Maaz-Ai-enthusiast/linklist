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

class Node {
    public:
    int val;
    Node* next; // Pointer to the next Node object in the list

    // Constructor to initialize the node with a given value
    Node(int data) {
        this->val = data; // Initialize the node's value
        next = NULL;       // Set the next pointer to NULL by default
    }
};

class LinkedList {
    private:
        Node* head; // Head of the linked list

    public:
        // Constructor to initialize the linked list
        LinkedList() {
            head = NULL;
        }

        // Destructor to delete all nodes in the list (deallocated automatically when the object is destroyed)
        ~LinkedList() {
            clear();  // Use the clear function to delete all nodes
        }

        // Function to clear the list and deallocate memory for all nodes
        void clear() {
            Node* current = head;  // Start with the head node
            while (current != NULL) {
                Node* nextNode = current->next;  // Save the pointer to the next node
                delete current;  // Delete the current node to free its memory
                current = nextNode;  // Move to the next node
            }
            head = NULL;  // After clearing, set head to NULL to indicate the list is empty
        }
};


// insert a node into start of linklist having constant time complexity
void insertAtStart(Node* &head, int data) {
    Node* new_node = new Node(data);  // Create a new node with the given data
    if (head == NULL) {  // If the list is empty
        head = new_node;  // Set the new node as the head
    } else {
        new_node->next = head;  // Point the new node to the current head
        head = new_node;  // Update head to the new node
    }
}




// insert a node at specified position

void insertAtPosition(Node*& head, int val, int pos) {
    if (pos < 1) {
        cout << "Invalid position. Must be greater than or equal to 1." << endl;
        return;
    }

    Node* new_node = new Node(val);

    // Special case: Insert at the head
    if (pos == 1) {
        new_node->next = head;
        head = new_node;
        return;
    }

    Node* temp = head;
    int count = 1;

    // Traverse to the position before the desired position
    while (temp != nullptr && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        // Position is out of bounds
        cout << "Position out of bounds." << endl;
        delete new_node; // Avoid memory leak
        return;
    }

    // Insert the new node
    new_node->next = temp->next;
    temp->next = new_node;
}

// insert the node at the end of the linklist

void insertAtEnd(Node* &head, int data){
    Node* new_node = new Node(data);
    if(head == NULL){
        head = new_node;
        return;
    }
    Node* temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

// update the value of the node at the specified position

void updateAtPosition(Node* head, int val, int pos) {
    if (head == nullptr) {
        cout << "Error: The list is empty." << endl;
        return;
    }

    if (pos < 1) {
        cout << "Error: Invalid position. Position must be >= 1." << endl;
        return;
    }

    Node* temp = head;
    int count = 1;

    // Traverse the list to find the desired position
    while (temp != nullptr && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        // Position is out of bounds
        cout << "Error: Position out of bounds." << endl;
        return;
    }

    // Update the value at the specified position
    temp->val = val;
}


// delete the first node

void deleteAtStart(Node*& head) {
    if (head == nullptr) {
        cout << "Error: List is already empty." << endl;
        return;
    }

    Node* temp = head;  // Store the current head
    head = head->next;  // Update head to the next node
    delete temp;        // Free memory for the removed node
}

// delete the last node

void deleteAtEnd(Node*& head) {
    if (head == nullptr) return;  // Empty list case
    
    if (head->next == nullptr) {  // Single-node list case
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;  // Traverse to the last node
    }

    // Now `temp` is pointing to the last node
    delete temp;   // Delete the last node
    temp = nullptr;
}



// delete the node at the specified position

void deleteAtPosition(Node* head, int pos) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    if (pos < 1) {
        cout << "Invalid position. Must be greater than or equal to 1." << endl;
        return;
    }

    // Special case: Deleting the head node
    if (pos == 1) {
        Node* toDelete = head;
        head = head->next;  // Move the head pointer to the next node
        free(toDelete);     // Deallocate memory
        return;
    }

    Node* temp = head;
    int count = 1;

    // Traverse to the node just before the position
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    // Check if position is out of bounds
    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of bounds." << endl;
        return;
    }

    // Delete the node at the specified position
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);  // Deallocate memory
}


// display the list of nodes
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
// here  n is a pointer to a Node object, not the object itself. 
// It points to the memory location where the Node object is stored

Node* head =NULL;
insertAtStart(head, 10);

insertAtStart(head, 20);

insertAtStart(head, 30);

display(head); // Displaying the linked list

insertAtEnd(head, 40);

display(head); // Displaying the linked list

insertAtPosition(head, 50, 2);

display(head); // Displaying the linked list

updateAtPosition(head, 60, 2);

display(head); // Displaying the linked list

deleteAtStart(head);

display(head); // Displaying the linked list

deleteAtEnd(head);

display(head); // Displaying the linked list

deleteAtPosition(head, 2);

display(head); // Displaying the linked list


return 0;
}