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
        return;
    }
    void display()
    {
        if (last == NULL) 
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = last->next;  // first node

        do 
        {
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
    m.push(89);
    m.push(76);
    m.push(35);

    m.display();
}