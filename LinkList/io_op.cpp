#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    // Constructor for easy initialization
    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // 1. Insertion at the beginning
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 2. Insertion at the end
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // 3. Deletion by value
    void deleteNode(int val) {
        if (!head) return;

        // If the head holds the value
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // 4. Display the list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main() {
    LinkedList list;
    
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtHead(5);
    
    cout << "List after insertions: ";
    list.display(); // Output: 5 -> 10 -> 20 -> NULL

    list.deleteNode(10);
    cout << "List after deleting 10: ";
    list.display(); // Output: 5 -> 20 -> NULL

    return 0;
}