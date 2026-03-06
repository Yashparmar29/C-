#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

class method
{
    node *head = NULL,*temp,*newnode;

    int n,value;
    public :

    method()
    {
        if(head == NULL)
        {
            cout << "Enter number of node :- ";
            cin >> n;

            for(int i=0;i<n;i++)
            {
                newnode = new node();
                
                cout << "Enter value :- ";
                cin >> newnode -> data ;
                
                newnode -> next;

                if(head == NULL)
                {
                    head = newnode;
                    temp = head;
                }
                else
                {
                    temp -> next = newnode;
                    temp = newnode;
                }
            }
        }

        cout << "Linkedlidt -> ";
        temp = head;

        if(head == NULL)
        {
            cout << "linklist is Empty...";
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp -> data << " -> ";
                temp = temp ->next;

            }
            cout << "Null";
        }
    }
};
int main()
{
    method m;
}