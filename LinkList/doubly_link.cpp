struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    // 1. Insertion at the Head
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head != nullptr) {
            head->prev = newNode;
            newNode->next = head;
        }
        head = newNode;
    }

    // 2. Insertion at the Tail
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // 3. Deletion of a specific node
    void deleteNode(int val) {
        if (!head) return;

        Node* curr = head;
        while (curr && curr->data != val) {
            curr = curr[0].next;
        }

        if (!curr) return; // Value not found

        // If it's the head node
        if (curr == head) {
            head = curr->next;
        }

        // Adjust the 'next' pointer of the previous node
        if (curr->prev != nullptr) {
            curr->prev->next = curr->next;
        }

        // Adjust the 'prev' pointer of the next node
        if (curr->next != nullptr) {
            curr->next->prev = curr->prev;
        }

        delete curr;
    }

    void displayForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
#include <iostream>
using namespace std;

// Node and Class definitions from previous steps would go here

int main() {
    DoublyLinkedList list;

    cout << "--- Building the List ---" << endl;
    
    // Adding 10 to an empty list
    list.insertAtHead(10); 
    
    // Adding 5 to the front: 5 <-> 10
    list.insertAtHead(5);   
    
    // Adding 20 to the back: 5 <-> 10 <-> 20
    list.insertAtTail(20);  
    
    // Adding 30 to the back: 5 <-> 10 <-> 20 <-> 30
    list.insertAtTail(30);  

    cout << "Current List: ";
    list.displayForward();

    cout << "\n--- Testing Deletions ---" << endl;

    // Delete the head node (5)
    cout << "Deleting Head (5)..." << endl;
    list.deleteNode(5);
    list.displayForward();

    // Delete a middle node (20)
    cout << "Deleting Middle Node (20)..." << endl;
    list.deleteNode(20);
    list.displayForward();

    // Delete the tail node (30)
    cout << "Deleting Tail (30)..." << endl;
    list.deleteNode(30);
    list.displayForward();

    cout << "\nFinal List State: ";
    list.displayForward(); // Should just be: 10 <-> NULL

    return 0;
}