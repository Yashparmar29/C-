#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteNode(int val) {
        if (!head) return;
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

    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    int sum() {
        int s = 0;
        Node* temp = head;
        while (temp) {
            s += temp->data;
            temp = temp->next;
        }
        return s;
    }
};

int main() {
    SinglyLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "List: ";
    list.display();

    cout << "Sum: " << list.sum() << endl;

    int find = 20;
    cout << "Search " << find << ": " << (list.search(find) ? "Found" : "Not Found") << endl;

    cout << "Deleting 20..." << endl;
    list.deleteNode(20);
    
    cout << "List: ";
    list.display();
    
    cout << "New Sum: " << list.sum() << endl;

    return 0;
}