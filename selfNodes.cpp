#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = nullptr;
    }
};

void insertAtStart(Node* &head, int data) {
    Node* new_node = new Node(data);  // Use new to allocate memory
    new_node->next = head;
    head = new_node;
}

void displayNodes(Node* &head) {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        cout << "-->" << temp->val;
        temp = temp->next;
        count++;
    }

    cout << "-->NULL" << endl;
    cout << "Total Nodes: " << count << endl;
}

void insertAtPosition(Node* &head, int data, int pos) {
    Node* new_node = new Node(data);  // Use new to allocate memory
    Node* temp = head;
    int count = 1;

    while (count < pos - 1 && temp != nullptr) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void insertAtEnd(Node* &head, int data) {
    Node* new_node = new Node(data);  // Use new to allocate memory
    if (head == nullptr) {
        head = new_node;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new_node;
    
}

void deleteAtStart(Node* &head) {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;  // Use delete to deallocate memory
}

void deleteAtEnd(Node* &head) {
    if (head == nullptr) {
        return;
    }
    if (head->next == nullptr) {
        delete head;  // Use delete to deallocate memory
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;  // Use delete to deallocate memory
    temp->next = nullptr;
}

void deleteAlternateNodes(Node* &head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* current = head;
    Node* nodeToDelete = head->next;
    while (current != nullptr && nodeToDelete != nullptr) {
        current->next = nodeToDelete->next;
        delete nodeToDelete;  // Use delete to deallocate memory
        current = current->next;

        if (current != nullptr) {
            nodeToDelete = current->next;
        }
    }
}

void deleteDuplicateNodes(Node* &head) {
    if (head == nullptr) return;

    Node* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->val == current->next->val) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;  // Use delete to deallocate memory
        } else {
            current = current->next;
        }
    }
}

void reversePrint(Node* &head) {
    if (head == nullptr) {
        return;
    }

    reversePrint(head->next);
    cout << head->val << "-->";
}

Node* reverseList(Node* &head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void findFirstAppearance(Node* head, int target) {
    int position = 1;
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->val == target) {
            cout << "Found at position ----> " << position << endl;
            return;
        }
        temp = temp->next;
        position++;
    }

    cout << "Not found ----->" << endl;
}

int main() {
    Node* head = nullptr;

    insertAtStart(head, 10);
    insertAtStart(head, 20);
    insertAtStart(head, 30);
    insertAtStart(head, 40);
    insertAtStart(head, 50);
    insertAtStart(head, 80);
    insertAtStart(head, 80);
    insertAtStart(head, 80);
    insertAtStart(head, 80);

    displayNodes(head);
    reversePrint(head);
    cout << endl;

    deleteDuplicateNodes(head);
    displayNodes(head);

    findFirstAppearance(head, 30);
    findFirstAppearance(head, 130);

  Node* reversedHead = reverseList(head);
    displayNodes(reversedHead);

    return 0;
}
