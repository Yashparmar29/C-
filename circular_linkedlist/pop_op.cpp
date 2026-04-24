#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
class method
{
    Node* last = NULL;
    public :
    void push(int value) 
    {
        Node* newNode = new Node();
        newNode->data = value;

        if (last == NULL) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }
    void pop() 
    {
        if (last == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = last->next;

        if (last == temp) 
        {
            delete temp;
            last = NULL;
        } 
        else 
        {
            last->next = temp->next;
            delete temp;
        }
    }
    void display() 
    {
        if (last == NULL) 
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = last->next;  
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } 
        while (temp != last->next);

        cout << "(back to start)\n";
    }
};
int main()
{
    method m;
    m.push(28);
    m.push(36);
    m.push(67);

    cout << "List: ";
    m.display();
    
    m.pop();
    m.display();
}