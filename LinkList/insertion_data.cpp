#include<iostream>
using namespace std;
class node
{
    public :
        int data;
        node* next;

        node(int v)
        {
            data = v;
            next = NULL;
        }
};
class method 
{
    public :

        node* head;
        node* tail;

        method()
        {
            head = tail = NULL;
        }
};

int main()
{
    return 0;
}